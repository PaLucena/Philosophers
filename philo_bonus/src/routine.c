/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/05 00:14:55 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_death(void *param)
{
	t_philo	*plato;

	plato = (t_philo *)param;
	while(42)
	{
		sem_wait(plato->sem_death);
		if (get_time() - plato->last_meal >= plato->cave->time_to_die)
		{
			printf("%ld %i died\n", get_time() - plato->cave->set_time,
				plato->index);
			sem_post(plato->cave->alive);
		}
		sem_post(plato->sem_death);
	}
	return (NULL);
}

void	r_think(t_philo *plato)
{
	printf("%ld %i is thinking\n", get_time() - plato->cave->set_time,
		plato->index);
}

void	r_sleep(t_philo *plato)
{
	printf("%ld %i is sleeping\n", get_time() - plato->cave->set_time,
		plato->index);
}

void	r_eat(t_philo *plato)
{
	sem_wait(plato->cave->forks);
	printf("%ld %i has taken a fork\n", get_time() - plato->cave->set_time,
		plato->index);
	sem_wait(plato->cave->forks);
	printf("%ld %i has taken a fork\n", get_time() - plato->cave->set_time,
		plato->index);
	printf("%ld %i is eating\n", get_time() - plato->cave->set_time,
		plato->index);
	sem_wait(plato->sem_death);
	plato->last_meal = get_time();
	sem_post(plato->sem_death);
	plato->meals++;
	ft_usleep(plato->cave->time_to_eat);
	sem_post(plato->cave->forks);
	sem_post(plato->cave->forks);
}

void	routine(t_philo *plato)
{
	plato->last_meal = get_time();
	pthread_create(&plato->self_death, NULL, philo_death, plato);
	if (plato->index % 2 == 0)
		r_think(plato);
	while (42)
	{
		r_eat(plato);
		r_sleep(plato);
		r_think(plato);
	}
}
