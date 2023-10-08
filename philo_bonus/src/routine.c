/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/09 01:06:00 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_death(void *param)
{
	t_philo	*plato;

	plato = (t_philo *)param;
	while (42)
	{
		sem_wait(plato->cave->race_death);
		if (get_time() - plato->last_meal >= plato->cave->t_die)
		{
			printf("Tiempo sin comer: %ld\n", get_time() - plato->last_meal);
			printf("%ld %i died\n", get_time() - plato->cave->t_start,
				plato->index);
			sem_post(plato->cave->alive);
			break ;
		}
		sem_post(plato->cave->race_death);
	}
	sem_post(plato->cave->race_death);
	return (NULL);
}

void	r_think(t_philo *plato)
{
	printf("%ld %i is thinking\n", get_time() - plato->cave->t_start,
		plato->index);
}

void	r_sleep(t_philo *plato)
{
	printf("%ld %i is sleeping\n", get_time() - plato->cave->t_start,
		plato->index);
}

void	r_eat(t_philo *plato)
{
	sem_wait(plato->cave->forks);
	printf("%ld %i has taken a fork\n", get_time() - plato->cave->t_start,
		plato->index);
	sem_wait(plato->cave->forks);
	printf("%ld %i has taken a fork\n", get_time() - plato->cave->t_start,
		plato->index);
	printf("%ld %i is eating\n", get_time() - plato->cave->t_start,
		plato->index);
	sem_wait(plato->cave->race_death);
	plato->last_meal = get_time();
	sem_post(plato->cave->race_death);
	plato->meals++;
	ft_usleep(plato->cave->t_eat);
	sem_post(plato->cave->forks);
	sem_post(plato->cave->forks);
}

void	*routine(void *param)
{
	t_philo *plato;

	plato = (t_philo *)param;
	sem_wait(plato->cave->race_death);
	sem_post(plato->cave->race_death);
	if (plato->index % 2 == 0)
		r_think(plato);
	//printf("%ld ------- Despues\n", get_time() - plato->cave->t_start);
	while (42)
	{
		r_eat(plato);
		r_sleep(plato);
		r_think(plato);
	}
	return (NULL);
}

void	ft_philo(t_philo *plato)
{
	plato->last_meal = get_time();
	pthread_create(&plato->self_death, NULL, philo_death, plato);
	pthread_create(&plato->routine, NULL, routine, plato);
	sem_wait(plato->cave->alive);
	sem_post(plato->cave->alive);
	printf("%ld ------- Despues\n", get_time() - plato->cave->t_start);
	pthread_join(plato->self_death, NULL);
	pthread_join(plato->routine, NULL);
	return ;
}
