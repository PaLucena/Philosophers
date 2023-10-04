/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:20 by palucena          #+#    #+#             */
/*   Updated: 2023/10/05 00:06:27 by palucena         ###   ########.fr       */
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
		if (ft_atol(av[i]) < 0 || ft_atol(av[i]) > INT32_MAX)
		{
			if (i != 5)
				write(1, "Error\n", 6);
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (!check_args(av, ac))
			return (1);
		filosofar(ac, av);
	}
	else
		printf("Error\n");
	return (0);
}
