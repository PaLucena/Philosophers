/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/13 16:50:09 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	single_philo(t_philo *ph)
{
	if (ph->meals_left == 0)
		exit (0);
	sem_wait(ph->cave->forks);
	print_status(ph, 'f');
	ft_usleep(ph->cave->t_die);
	print_status(ph, 'd');
}

void	ph_day(t_philo	*ph)
{
	if (ph->index > ph->cave->n_ph / 2)
		print_status(ph, 't');
	//	ft_usleep(100);
	while (1)
	{
		if (ph->meals_left == 0)
			exit (0);
		if (ft_die(ph))
			break ;
		if (!ft_die(ph))
			r_eat(ph);
		if (!ft_die(ph))
			r_sleep(ph);
		if (!ft_die(ph))
			r_think(ph);
	}
	sem_post(ph->cave->sem_finish);
}

void	*routine(t_philo *ph)
{
	ph->t_last_meal = get_time();
	if (ph->cave->n_ph == 1)
		single_philo(ph);
	else
		ph_day(ph);
	return (0);
}
