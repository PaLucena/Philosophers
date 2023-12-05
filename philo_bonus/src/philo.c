/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/12/05 19:02:23 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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
			print_status(ph, 'd');
			break ;
		}
	}
	sem_post(ph->cave->death);
	return (NULL);
}

void	ft_philo(t_philo *ph)
{
	pthread_t	routine;
	pthread_t	death_check;

	ph->t_last_meal = get_time();
	sem_post(ph->cave->init);
	if (ph->cave->n_ph == 1)
		single_philo(ph);
	else if (ph->meals_left != 0)
	{
		pthread_create(&routine, NULL, ft_routine, ph);
		pthread_create(&death_check, NULL, ft_check_death, ph);
		sem_wait(ph->cave->death);
		//printf("Bloqueo: %i en %ld\n", ph->index, get_time());
		ph->lock = true;
		sem_post(ph->cave->death);
		pthread_join(routine, NULL);
		pthread_join(death_check, NULL);
	}
	own_semaphore(ph, 2);
	exit (0);
}
