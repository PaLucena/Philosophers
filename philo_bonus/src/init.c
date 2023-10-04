/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/04 23:53:51 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_lights(t_cave *cave)
{
	int	i;

	sem_unlink("all_eaten");
	cave->all_eaten = sem_open("all_eaten", O_CREAT, 0600, cave->n_philo);
	i = 0;
	while (++i <= cave->n_philo)
	{
		sem_unlink(ft_itoa(i));
		cave->philos[i].sem_death = sem_open(ft_itoa(i), O_CREAT, 0600, 1);
		sem_wait(cave->all_eaten);
	}
	sem_unlink("alive");
	cave->alive = sem_open("alive", O_CREAT, 0600, 0);
	sem_unlink("forks");
	cave->forks = sem_open("forks", O_CREAT, 0600, cave->n_philo);
}

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
	cave->philo_id = malloc(sizeof(pid_t) * cave->n_philo);
	cave->philos = malloc(sizeof(t_philo) * cave->n_philo);
	if (!cave->philo_id|| !cave->philos)
		return (NULL);
	init_lights(cave);
	cave->set_time = get_time();
	return (cave);
}

void	init_philo(t_cave *cave)
{
	int		i;

	i = -1;
	while (++i < cave->n_philo)
	{
		cave->philos[i].index = i + 1;
		cave->philos[i].meals = 0;
		cave->philos[i].cave = cave;
	}
}
