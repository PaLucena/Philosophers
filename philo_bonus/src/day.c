/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:27 by palucena          #+#    #+#             */
/*   Updated: 2023/10/13 12:33:34 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

bool	ft_die(t_philo *ph)
{
	if (ph->finished)
		return (true);
	sem_wait(ph->cave->sem_meal);
	if (get_time() - ph->t_last_meal >= ph->cave->t_die)
	{
		sem_post(ph->cave->sem_meal);
		print_status(ph->cave, ph->index, 'd');
		sem_post(ph->cave->alive);
		ph->finished = true;
		return (true);
	}
	sem_post(ph->cave->sem_meal);
	return (false);
}

void	r_think(t_philo *ph)
{
	print_status(ph->cave, ph->index, 't');
}

void	r_sleep(t_philo *ph)
{
	print_status(ph->cave, ph->index, 's');
	ft_usleep(ph->cave->t_sleep);
}

void	r_eat(t_philo *ph)
{
	sem_wait(ph->cave->forks);
	print_status(ph->cave, ph->index, 'f');
	sem_wait(ph->cave->forks);
	print_status(ph->cave, ph->index, 'f');
	print_status(ph->cave, ph->index, 'e');
	sem_wait(ph->cave->sem_meal);
	ph->t_last_meal = get_time();
	sem_post(ph->cave->sem_meal);
	ph->meals++;
	ft_usleep(ph->cave->t_eat);
	sem_post(ph->cave->forks);
	sem_post(ph->cave->forks);
}
