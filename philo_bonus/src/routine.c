/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:27 by palucena          #+#    #+#             */
/*   Updated: 2023/12/06 19:32:42 by palucena         ###   ########.fr       */
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

int	r_eat(t_philo *ph)
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
	ft_usleep(ph->cave->t_eat);
	sem_post(ph->cave->forks);
	sem_post(ph->cave->forks);
	return (ph->meals_left);
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
	while (!ph->lock)
	{
		if (r_eat(ph) == 0)
			break ;
		r_sleep(ph);
		r_think(ph, 1);
	}
	return (NULL);
}
