/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:20 by palucena          #+#    #+#             */
/*   Updated: 2023/10/09 01:06:21 by palucena         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_cave	c;
	if (argc == 5 || argc == 6)
	{
		if (!check_args(argv, argc))
			return (1);
		init_struct(&c, argc, argv);
	}
	else
		printf("Error\n");
	return (0);
}
