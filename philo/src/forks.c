/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:37 by palucena          #+#    #+#             */
/*   Updated: 2023/10/09 12:30:10 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pick_f(t_philo *plato)
{
	if (plato->index % 2 == 0)
	{
		pthread_mutex_lock(plato->fork_l);
		print_status(plato->cave, plato->index, 'f');
		pthread_mutex_lock(plato->fork_r);
		print_status(plato->cave, plato->index, 'f');
	}
	else
	{
		pthread_mutex_lock(plato->fork_r);
		print_status(plato->cave, plato->index, 'f');
		pthread_mutex_lock(plato->fork_l);
		print_status(plato->cave, plato->index, 'f');
	}
}

void	drop_f(t_philo *plato)
{
	if (plato->index % 2 == 0)
	{
		pthread_mutex_unlock(plato->fork_l);
		pthread_mutex_unlock(plato->fork_r);
	}
	else
	{
		pthread_mutex_unlock(plato->fork_r);
		pthread_mutex_unlock(plato->fork_l);
	}
}
