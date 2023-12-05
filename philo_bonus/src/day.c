/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:27 by palucena          #+#    #+#             */
/*   Updated: 2023/12/05 16:36:31 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	r_think(t_philo *ph)
{
	print_status(ph, 't');
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
