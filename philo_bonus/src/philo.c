/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/12/08 19:01:25 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ph_life(t_cave *c, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < c->n_ph)
	{
		c->pid[i] = fork();
		if (c->pid[i] == 0)
		{
			ph->index = i + 1;
			ph->t_start = get_time();
			own_semaphore(ph, 1);
			ft_philo(ph);
		}
		i++;
	}
}

void	*ft_check_death(void *param)
{
	t_philo	*ph;
	long	check;

	ph = (t_philo *)param;
	while (!ph->lock)
	{
		sem_wait(ph->shield);
		check = get_time() - ph->t_last_meal;
		sem_post(ph->shield);
		if (check >= ph->cave->t_die)
		{
			sem_wait(ph->cave->d_lock);
			print_status(ph, 'd');
			break ;
		}
	}
	sem_post(ph->cave->death);
	sem_post(ph->cave->d_lock);
	return (NULL);
}

void	ft_philo(t_philo *ph)
{
	pthread_t	routine;
	pthread_t	death_check;

	ph->t_last_meal = get_time();
	if (ph->cave->n_ph == 1)
		single_philo(ph);
	else if (ph->meals_left != 0)
	{
		pthread_create(&routine, NULL, ft_routine, ph);
		pthread_create(&death_check, NULL, ft_check_death, ph);
		sem_wait(ph->cave->death);
		ph->lock = true;
		sem_post(ph->cave->death);
		pthread_join(routine, NULL);
		pthread_join(death_check, NULL);
	}
	own_semaphore(ph, 2);
	exit (0);
}
