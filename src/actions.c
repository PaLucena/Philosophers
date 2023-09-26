/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:12:13 by palucena          #+#    #+#             */
/*   Updated: 2023/09/26 17:47:38 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_eat(t_philo *plato)
{
	pthread_mutex_lock(plato->fork_l);
	plato->last_meal = ft_time() - plato->cave->set_time;
	pthread_mutex_lock(plato->cave->write);
	printf("%ld %i has taken a fork\n", plato->last_meal, plato->index);
	pthread_mutex_lock(plato->fork_r);
	printf("%ld %i has taken a fork\n", plato->last_meal, plato->index);
	printf("%ld %i is eating\n", plato->last_meal, plato->index);
	pthread_mutex_unlock(plato->cave->write);
	plato->meals++;
	usleep(plato->cave->time_to_eat);
	pthread_mutex_unlock(plato->fork_l);
	pthread_mutex_unlock(plato->fork_r);
	return (0);
}

int	ft_sleep(t_philo *plato)
{
	long	tiempo;

	pthread_mutex_lock(plato->cave->write);
	tiempo = ft_time() - plato->cave->set_time;
	printf("%ld %i is sleeping\n", tiempo, plato->index);
	pthread_mutex_unlock(plato->cave->write);
	usleep(plato->cave->time_to_sleep);
	return (0);
}

int	ft_think(t_philo *plato)
{
	long	tiempo;

	pthread_mutex_lock(plato->cave->write);
	tiempo = ft_time() - plato->cave->set_time;
	printf("%ld %i is thinking\n", tiempo, plato->index);
	pthread_mutex_unlock(plato->cave->write);
	return (0);
}
