/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/09/25 17:31:44 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_cave	*init_cave(int ac, char **av)
{
	t_cave	*cueva;

	cueva = malloc(sizeof(t_cave));
	if (!cueva)
		return (NULL);
	cueva->n_philo = ft_atoi(av[1]);
	cueva->time_to_die = ft_atoi(av[2]);
	cueva->time_to_eat = ft_atoi(av[3]);
	cueva->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		cueva->n_of_meals = ft_atoi(av[5]);
	else
		cueva->n_of_meals = -1;
	cueva->philo_id = malloc(sizeof(pthread_t) * cueva->n_philo);
	cueva->fork_id = malloc(sizeof(pthread_mutex_t) * cueva->n_philo);
	cueva->philos = malloc(sizeof(t_philo) * cueva->n_philo);
	if (!cueva->philo_id || !cueva->fork_id || !cueva->philos)
		return (NULL);
	return (cueva);
}

void	init_philo(t_cave *cueva)
{
	int		i;

	i = -1;
	while (++i < cueva->n_philo)
		pthread_mutex_init(&cueva->fork_id[i], NULL);
	i = -1;
	while (++i < cueva->n_philo)
	{
		cueva->philos[i].index = i + 1;
		cueva->philos[i].cave = cueva;
		cueva->philos[i].fork_r = &cueva->fork_id[i];
		if (i == 0)
			cueva->philos[i].fork_l = &cueva->fork_id[cueva->n_philo - 1];
		else
			cueva->philos[i].fork_l = &cueva->fork_id[i - 1];
	}
}

void	birth(t_cave *cueva)
{
	int	i;

	i = -1;
	while (++i < cueva->n_philo)
		pthread_create(&cueva->philo_id[i], NULL, cycle, (void *)&cueva->philos[i]);
}

void	filosofar(int ac, char **av)
{
	t_cave	*cueva;

	cueva = init_cave(ac, av);
	/* if (!cueva)
		return (NULL); */
	init_philo(cueva);
	birth(cueva);
}

// cosas de structs filosofantes
