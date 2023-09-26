/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/09/25 17:26:55 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*cycle(void *param)
{
	t_philo	*plato;

	plato = (t_philo *)param;
	printf("Entró: %i\n", plato->index);
	/* pthread_mutex_lock(plato->fork_l);
	pthread_mutex_lock(plato->fork_r);
	usleep(plato->cave->time_to_eat * 1000);
	pthread_mutex_unlock(plato->fork_l);
	pthread_mutex_unlock(plato->fork_r); */
	return (NULL);
}