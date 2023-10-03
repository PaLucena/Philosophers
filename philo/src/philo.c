/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/10/03 15:00:32 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_life(t_cave *cueva)
{
	int		i;

	i = -1;
	while (++i < cueva->n_philo)
		pthread_create(&cueva->philo_id[i], NULL, cycle, &cueva->philos[i]);
	while (1)
	{
		i = check_status(cueva);
		if (i != 0)
		{
			if (i > 0)
				print_status(cueva, i, 'd');
			pthread_mutex_lock(cueva->life);
			if (i < 0)
				cueva->all_eaten = true;
			pthread_mutex_unlock(cueva->life);
			break ;
		}
	}
	i = -1;
	while (++i < cueva->n_philo)
		pthread_join(cueva->philo_id[i], NULL);
}

void	ft_afterlife(t_cave *cueva)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(cueva->write);
	pthread_mutex_destroy(cueva->meal);
	pthread_mutex_destroy(cueva->life);
	while (++i < cueva->n_philo)
		pthread_mutex_destroy(&cueva->fork_id[i]);
	free(cueva->write);
	free(cueva->meal);
	free(cueva->life);
	free(cueva->fork_id);
	free(cueva->philo_id);
	free(cueva->philos);
	free(cueva);
}

void	filosofar(int ac, char **av)
{
	t_cave	*cueva;

	cueva = init_cave(ac, av);
	init_philo(cueva);
	ft_life(cueva);
	ft_afterlife(cueva);
}
