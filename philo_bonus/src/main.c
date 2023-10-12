/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:20 by palucena          #+#    #+#             */
/*   Updated: 2023/10/12 17:52:31 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

bool	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (!ft_is_number(argv[i]))
			return (false);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) < 0 || ft_atol(argv[i]) > INT32_MAX)
			return (false);
		i++;
	}
	return (true);
}

/* void	ft_leaks(void)
{
	system("leaks -q philo_bonus");
} */

int	main(int argc, char **argv)
{
	t_cave	*c;
	int		i;

	//atexit(ft_leaks);
	if ((argc != 5 && argc != 6) || !check_args(argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	c = init_struct(argc, argv);
	ph_life(c);
	i = 0;
	ph_death(c);
	return (0);
}
