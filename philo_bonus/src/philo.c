/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/10/05 00:07:33 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_death(void *param)
{
	t_cave	*cave;
	int		i;

	cave = (t_cave *)param;
	sem_wait(cave->alive);
	i = -1;
	while (++i < cave->n_philo)
		kill(cave->philo_id[i], SIGKILL);
	return (NULL);
}

void	*ft_food(void *param)
{
	t_cave	*cave;
	int		i;

	cave = (t_cave *)param;
	i = 0;
	while (++i <= cave->n_philo)
		sem_wait(cave->all_eaten);
	i = -1;
	while (++i < cave->n_philo)
		kill(cave->philo_id[i], SIGKILL);
	return (NULL);
}

void	ft_life(t_cave *cave)
{
	int		i;

	i = -1;
	while (++i < cave->n_philo)
	{
		cave->philo_id[i] = fork();
		if (cave->philo_id[i] != 0)
			routine(&cave->philos[i]);
	}
	pthread_create(&cave->death, NULL, ft_death, cave);
	if (cave->max_meals >= 0)
		pthread_create(&cave->food, NULL, ft_food, cave);
}

void	ft_afterlife(t_cave *cave)
{
	// limpiar todo
	int	i;
	i = -1;
	while (++i < cave->n_philo)
		//a
	free(cave->philo_id);
	free(cave->philos);
	free(cave);
}

void	filosofar(int ac, char **av)
{
	t_cave	*cave;

	cave = init_cave(ac, av);
	init_philo(cave);
	ft_life(cave);
	ft_afterlife(cave);
}
