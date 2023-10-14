/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/14 20:30:43 by palucena         ###   ########.fr       */
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
	while (1)
	{
		if (ph->meals_left == 0)
			exit (0);
		ft_die(ph);
		r_eat(ph);
		ft_die(ph);
		r_sleep(ph);
		ft_die(ph);
		r_think(ph);
	}
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
