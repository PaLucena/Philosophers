/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/04 20:51:33 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_cave	*init_cave(int ac, char **av)
{
	t_cave	*cave;

	cave = malloc(sizeof(t_cave));
	if (!cave)
		return (NULL);
	cave->n_philo = ft_atol(av[1]);
	cave->time_to_die = (ft_atol(av[2]));
	cave->time_to_eat = (ft_atol(av[3]));
	cave->time_to_sleep = (ft_atol(av[4]));
	if (ac == 6)
		cave->max_meals = ft_atol(av[5]);
	else
		cave->max_meals = -1;
	cave->philo_id = malloc(sizeof(pthread_t) * cave->n_philo);
	cave->fork_id = malloc(sizeof(pthread_mutex_t) * cave->n_philo);
	cave->philos = malloc(sizeof(t_philo) * cave->n_philo);
	cave->write = malloc(sizeof(pthread_mutex_t));
	cave->meal = malloc(sizeof(pthread_mutex_t));
	cave->life = malloc(sizeof(pthread_mutex_t));
	if (!cave->philo_id || !cave->fork_id || !cave->philos)
		return (NULL);
	cave->vivos = true;
	cave->all_eaten = false;
	cave->set_time = get_time();
	return (cave);
}

void	init_philo(t_cave *cave)
{
	int		i;

	i = -1;
	pthread_mutex_init(cave->write, NULL);
	pthread_mutex_init(cave->meal, NULL);
	pthread_mutex_init(cave->life, NULL);
	while (++i < cave->n_philo)
		pthread_mutex_init(&cave->fork_id[i], NULL);
	i = -1;
	while (++i < cave->n_philo)
	{
		cave->philos[i].index = i + 1;
		cave->philos[i].meals = 0;
		cave->philos[i].cave = cave;
		cave->philos[i].fork_r = &cave->fork_id[i];
		if (i == 0)
			cave->philos[i].fork_l = &cave->fork_id[cave->n_philo - 1];
		else
			cave->philos[i].fork_l = &cave->fork_id[i - 1];
	}
}
