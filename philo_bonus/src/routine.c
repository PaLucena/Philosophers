/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:27 by palucena          #+#    #+#             */
/*   Updated: 2023/12/09 13:09:17 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	r_think(t_philo *ph, bool d)
{
	long	think;

	think = (ph->cave->t_die - ph->cave->t_eat - \
		(get_time() - ph->t_last_meal)) / 2;
	if (think <= 0 && !d)
		think = 1;
	else if (think < 0)
		think = 0;
	if (d)
		print_status(ph, 't');
	ft_usleep(think);
}

void	r_sleep(t_philo *ph)
{
	print_status(ph, 's');
	ft_usleep(ph->cave->t_sleep);
}

void	r_eat(t_philo *ph)
{
	sem_wait(ph->cave->forks);
	print_status(ph, 'f');
	sem_wait(ph->cave->forks);
	print_status(ph, 'f');
	print_status(ph, 'e');
	sem_wait(ph->shield);
	ph->t_last_meal = get_time();
	sem_post(ph->shield);
	ph->meals_left--;
	if (ph->meals_left == 0)
		sem_post(ph->cave->full);
	ft_usleep(ph->cave->t_eat);
	sem_post(ph->cave->forks);
	sem_post(ph->cave->forks);
}

void	single_philo(t_philo *ph)
{
	if (ph->meals_left == 0)
		exit (0);
	sem_wait(ph->cave->forks);
	print_status(ph, 'f');
	ft_usleep(ph->cave->t_die);
	print_status(ph, 'd');
}

void	*ft_routine(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	if (ph->index % 2)
		r_think(ph, 0);
	while (1)
	{
		r_eat(ph);
		sem_wait(ph->shield);
		if (ph->lock)
			break ;
		sem_post(ph->shield);
		r_sleep(ph);
		r_think(ph, 1);
	}
	ph->lock = true;
	sem_post(ph->shield);
	return (NULL);
}
