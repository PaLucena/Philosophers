/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:20 by palucena          #+#    #+#             */
/*   Updated: 2023/09/27 18:55:59 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	check_args(char **av)
{
	int	i;

	i = 0;
	while (av[++i] != NULL)
	{
		if (!ft_is_number(av[i]))
			return (false);
	}
	if (ft_atoi(av[1]) <= 0)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (!check_args(av))
			return (1);
		filosofar(ac, av);
	}
	return (0);
}
