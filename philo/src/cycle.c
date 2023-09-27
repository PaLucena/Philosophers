/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/09/27 19:44:13 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	pick_fork(t_philo *plato)
{
	if (plato->index % 2 == 0)
	{
		pthread_mutex_lock(plato->fork_l);
		pthread_mutex_lock(plato->fork_r);
	}
	else
	{
		pthread_mutex_lock(plato->fork_r);
		pthread_mutex_lock(plato->fork_l);
	}
}

void	print_status(t_cave *cave, int index, char status)
{
	long	time;

	time = ft_time() - cave->set_time;
	pthread_mutex_lock(cave->write);
	if (cave->vivos)
	{
		if (status == 'f')
			printf("%ld %i has taken a fork\n", time, index);
		else if (status == 'e')
			printf("%ld %i is eating\n", time, index);
		else if (status == 's')
			printf("%ld %i is sleeping\n", time, index);
		else if (status == 't')
			printf("%ld %i is thinking\n", time, index);
		else if (status == 'd')
		{
			printf("%ld %i died\n", time, index);
			cave->vivos = false;
		}
	}
	pthread_mutex_unlock(cave->write);
}

void	*cycle(void *param)
{
	t_philo	*plato;

	plato = (t_philo *)param;
	plato->last_meal = ft_time() - plato->cave->set_time;
	while (plato->cave->vivos)
	{
		print_status(plato->cave, plato->index, 't');
		pick_fork(plato);
		print_status(plato->cave, plato->index, 'f');
		print_status(plato->cave, plato->index, 'f');
		print_status(plato->cave, plato->index, 'e');
		plato->last_meal = ft_time() - plato->cave->set_time;
		plato->meals++;
		ft_usleep(plato->cave->time_to_eat);
		pthread_mutex_unlock(plato->fork_l);
		pthread_mutex_unlock(plato->fork_r);
		print_status(plato->cave, plato->index, 's');
		ft_usleep(plato->cave->time_to_sleep);
	}
	return (NULL);
}
