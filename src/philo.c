/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/09/23 19:06:20 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>
#include <unistd.h>

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
}

void	ft_philo(t_cave *cueva)
{
	//crea philos
}
void	ft_mutex()
{
	//crea tenedores
}

void	filosofar(int ac, char **av)
{
	t_cave	*cueva;

	cueva = init_cave(ac, av);
	if (!cueva)
		return (NULL);
	ft_philo(cueva);

	pthread_create(&tid, NULL, &ft_start, NULL);
	pthread_join(tid, NULL);
}

// cosas de structs filosofantes
