/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/11/30 19:12:05 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	single_philo(t_philo *ph)
{
	if (ph->meals_left == 0)
		exit (0);
	sem_wait(ph->cave->forks);
	print_status(ph, 'f');
	ft_usleep(ph->cave->t_die, ph);
	print_status(ph, 'd');
}

void	*ft_routine(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	if (ph->index > ph->cave->n_ph / 2)
		print_status(ph, 't');
	while (1)
	{
		if (ph->meals_left == 0)
			exit (0);
		r_eat(ph);
		r_sleep(ph);
		r_think(ph);
	}
	return (NULL);
}

void	*ft_check_death(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	while (1)
	{
		if (get_time() - ph->t_last_meal >= ph->cave->t_die)
		{
			print_status(ph, 'd');
			sem_post(ph->cave->death);
			break ;
		}
		else if (ph->lock)
			break ;
	}
	ph->lock = true;
	return (NULL);
}

void	ft_philo(t_philo *ph)
{
	pthread_t	routine;
	pthread_t	death_check;

	sem_post(ph->cave->init);
	ph->t_last_meal = get_time();
	if (ph->cave->n_ph == 1)
		single_philo(ph);
	else
	{
		pthread_create(&routine, NULL, ft_routine, ph);
		pthread_create(&death_check, NULL, ft_check_death, ph);
		sem_wait(ph->cave->death);
		ph->lock = true;
		sem_post(ph->cave->death);
		pthread_join(routine, NULL);
		pthread_join(death_check, NULL);
	}
	exit (0);
}
