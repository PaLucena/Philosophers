/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:43:39 by palucena          #+#    #+#             */
/*   Updated: 2023/09/26 18:02:36 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	ft_error(int a)
{
	if (a == 1)
		write(1, "\nError\n", 7);
	return (true);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

bool	ft_is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
	}
	return (true);
}

bool	check_status(t_cave *cueva)
{
	long	curr_time;
	bool	full;
	int		i;

	i = -1;
	curr_time = ft_time() - cueva->set_time;
	while (++i < cueva->n_philo)
	{
		if (curr_time - cueva->philos[i].last_meal >= cueva->time_to_die)
			return (i + 1);
	}
	if (cueva->n_of_meals != -1)
	{
		i = -1;
		full = true;
		while (++i < cueva->n_philo)
		{
			if (cueva->philos[i].meals < cueva->n_of_meals)
				full = false;
		}
		if (full)
			return (-1);
	}
	return (0);
}
