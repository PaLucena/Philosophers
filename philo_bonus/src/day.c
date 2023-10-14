/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:27 by palucena          #+#    #+#             */
/*   Updated: 2023/10/14 20:38:30 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_die(t_philo *ph)
{
	if (get_time() - ph->t_last_meal >= ph->cave->t_die)
	{
		print_status(ph, 'd');
	}
}

void	r_think(t_philo *ph)
{
	print_status(ph, 't');
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
	ph->t_last_meal = get_time();
	ph->meals_left--;
	ft_usleep(ph->cave->t_eat);
	sem_post(ph->cave->forks);
	sem_post(ph->cave->forks);
}
