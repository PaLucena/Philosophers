/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:20 by palucena          #+#    #+#             */
/*   Updated: 2023/09/26 08:42:13 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	check_args(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (!ft_is_number(av[i]))
			return (false);
	}
	if (ft_atoi(av[0]) <= 0)
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
