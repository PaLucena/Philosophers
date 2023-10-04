/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/10/04 20:51:33 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_life(t_cave *cave)
{
	int		i;

	i = -1;
	while (++i < cave->n_philo)
		pthread_create(&cave->philo_id[i], NULL, cycle, &cave->philos[i]);
	while (1)
	{
		i = check_status(cave);
		if (i != 0)
		{
			if (i > 0)
				print_status(cave, i, 'd');
			pthread_mutex_lock(cave->life);
			if (i < 0)
				cave->all_eaten = true;
			pthread_mutex_unlock(cave->life);
			break ;
		}
	}
	i = -1;
	while (++i < cave->n_philo)
		pthread_join(cave->philo_id[i], NULL);
}

void	ft_afterlife(t_cave *cave)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(cave->write);
	pthread_mutex_destroy(cave->meal);
	pthread_mutex_destroy(cave->life);
	while (++i < cave->n_philo)
		pthread_mutex_destroy(&cave->fork_id[i]);
	free(cave->write);
	free(cave->meal);
	free(cave->life);
	free(cave->fork_id);
	free(cave->philo_id);
	free(cave->philos);
	free(cave);
}
