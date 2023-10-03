/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/03 13:28:10 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_cave	*init_cave(int ac, char **av)
{
	t_cave	*cueva;

	cueva = malloc(sizeof(t_cave));
	if (!cueva)
		return (NULL);
	cueva->n_philo = ft_atol(av[1]);
	cueva->time_to_die = (ft_atol(av[2]));
	cueva->time_to_eat = (ft_atol(av[3]));
	cueva->time_to_sleep = (ft_atol(av[4]));
	if (ac == 6)
		cueva->max_meals = ft_atol(av[5]);
	else
		cueva->max_meals = -1;
	cueva->philo_id = malloc(sizeof(pthread_t) * cueva->n_philo);
	cueva->fork_id = malloc(sizeof(pthread_mutex_t) * cueva->n_philo);
	cueva->philos = malloc(sizeof(t_philo) * cueva->n_philo);
	cueva->write = malloc(sizeof(pthread_mutex_t));
	cueva->meal = malloc(sizeof(pthread_mutex_t));
	cueva->life = malloc(sizeof(pthread_mutex_t));
	if (!cueva->philo_id || !cueva->fork_id || !cueva->philos)
		return (NULL);
	cueva->vivos = true;
	cueva->all_eaten = false;
	cueva->set_time = get_time();
	return (cueva);
}

void	init_philo(t_cave *cueva)
{
	int		i;

	i = -1;
	pthread_mutex_init(cueva->write, NULL);
	pthread_mutex_init(cueva->meal, NULL);
	pthread_mutex_init(cueva->life, NULL);
	while (++i < cueva->n_philo)
		pthread_mutex_init(&cueva->fork_id[i], NULL);
	i = -1;
	while (++i < cueva->n_philo)
	{
		cueva->philos[i].index = i + 1;
		cueva->philos[i].meals = 0;
		cueva->philos[i].cave = cueva;
		cueva->philos[i].fork_r = &cueva->fork_id[i];
		if (i == 0)
			cueva->philos[i].fork_l = &cueva->fork_id[cueva->n_philo - 1];
		else
			cueva->philos[i].fork_l = &cueva->fork_id[i - 1];
	}
}
