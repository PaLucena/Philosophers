/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:27 by palucena          #+#    #+#             */
/*   Updated: 2023/10/12 15:35:55 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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
	ph->last_meal = get_time();
	sem_post(ph->cave->sem_meal);
	ph->meals++;
	ft_usleep(ph->cave->t_eat);
	sem_post(ph->cave->forks);
	sem_post(ph->cave->forks);
}
