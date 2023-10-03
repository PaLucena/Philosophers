/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:41:14 by palucena          #+#    #+#             */
/*   Updated: 2023/10/03 19:02:20 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	check_args(char **av, int ac)
{
	int	i;

	i = 0;
	while (av[++i] != NULL)
	{
		if (!ft_is_number(av[i]))
			return (false);
	}
	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) <= 0 || ft_atol(av[i]) > INT32_MAX)
		{
			if (i != 5)
				write(1, "Error\n", 6);
			return (false);
		}
		i++;
	}
	return (true);
}

int	ft_starve(t_cave *cueva)
{
	long	end_time;
	int		i;

	i = -1;
	end_time = get_time() - cueva->set_time;
	while (++i < cueva->n_philo)
	{
		pthread_mutex_lock(cueva->meal);
		if (end_time - cueva->philos[i].last_meal >= cueva->time_to_die)
		{
			pthread_mutex_unlock(cueva->meal);
			return (cueva->philos[i].index);
		}
		else
			pthread_mutex_unlock(cueva->meal);
	}
	return (0);
}

int	check_status(t_cave *cueva)
{
	bool	full;
	int		i;

	i = ft_starve(cueva);
	if (i != 0)
		return (i);
	if (cueva->max_meals != -1)
	{
		i = -1;
		full = true;
		while (++i < cueva->n_philo)
		{
			pthread_mutex_lock(cueva->meal);
			if (cueva->philos[i].meals < cueva->max_meals)
				full = false;
			pthread_mutex_unlock(cueva->meal);
		}
		if (full)
			return (-1);
	}
	return (0);
}
