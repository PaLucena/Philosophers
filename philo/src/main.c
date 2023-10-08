/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:20 by palucena          #+#    #+#             */
/*   Updated: 2023/10/08 19:34:16 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_cave	*cave;

	if (ac == 5 || ac == 6)
	{
		if (!check_args(av, ac))
			return (1);
		cave = init_cave(ac, av);
		init_philo(cave);
		ft_life(cave);
		ft_afterlife(cave);
	}
	else
		printf("Error\n");
	return (0);
}
