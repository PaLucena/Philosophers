/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/12/03 00:35:08 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*ft_check_death(void *param)
{
	t_philo	*ph;
	long	check;

	ph = (t_philo *)param;
	
	while (1)
	{
		sem_wait(ph->cave->time);
		check = get_time() - ph->t_last_meal;
		sem_post(ph->cave->time);
		if (check >= ph->cave->t_die)
		{
			print_status(ph, 'd');
			sem_post(ph->cave->death);
			break ;
		}
		else if (ph->lock)
			break ;
	}
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
