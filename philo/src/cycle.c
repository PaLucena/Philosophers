/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/09 01:06:00 by palucena         ###   ########.fr       */
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

bool	has_starved(t_philo *plato)
{
	if ((long)(get_time - plato->last_meal) < plato->cave->t_die)
		return (true);
	return (false);
}

void	print_status(t_cave *cave, int index, char status)
{
	pthread_mutex_lock(cave->write);
	pthread_mutex_lock(cave->life);
	if (cave->vivos)
	{
		if (status == 'f')
			printf("%ld %i has taken a fork\n",
				get_time() - cave->t_start, index);
		else if (status == 'e' && has_starved(&cave->philos[index - 1]))
			printf("%ld %i is eating\n", get_time() - cave->t_start, index);
		else if (status == 's')
			printf("%ld %i is sleeping\n", get_time() - cave->t_start, index);
		else if (status == 't')
			printf("%ld %i is thinking\n", get_time() - cave->t_start, index);
		else if (status == 'd')
		{
			printf("%ld %i died\n", get_time() - cave->t_start, index);
			cave->vivos = false;
		}
	}
	pthread_mutex_unlock(cave->life);
	pthread_mutex_unlock(cave->write);
}

void	mufasa(t_philo *plato)
{
	print_status(plato->cave, plato->index, 'e');
	pthread_mutex_lock(plato->cave->meal);
	plato->last_meal = get_time() - plato->cave->t_start;
	plato->meals++;
	pthread_mutex_unlock(plato->cave->meal);
	ft_usleep(plato->cave->t_eat);
	drop_f(plato);
	print_status(plato->cave, plato->index, 's');
	ft_usleep(plato->cave->t_sleep);
	print_status(plato->cave, plato->index, 't');
}

void	one_philo(t_philo *plato)
{
	if (plato->cave->max_meals == 0)
		return ;
	else
	{
		pthread_mutex_lock(plato->fork_r);
		print_status(plato->cave, plato->index, 'f');
		pthread_mutex_unlock(plato->fork_r);
	}
}

void	*cycle(void *param)
{
	t_philo	*plato;

	plato = (t_philo *)param;
	pthread_mutex_lock(plato->cave->meal);
	plato->last_meal = get_time() - plato->cave->t_start;
	pthread_mutex_unlock(plato->cave->meal);
	if (plato->cave->n_philo == 1 || plato->cave->max_meals == 0)
		one_philo(plato);
	else
	{
		if (plato->index % 2 == 0 || plato->index == plato->cave->n_philo)
			print_status(plato->cave, plato->index, 't');
		while (1)
		{
			pthread_mutex_lock(plato->cave->life);
			if (!plato->cave->vivos || plato->cave->all_eaten)
				break ;
			pthread_mutex_unlock(plato->cave->life);
			pick_f(plato);
			mufasa(plato);
		}
		pthread_mutex_unlock(plato->cave->life);
	}
	return (NULL);
}
