/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:20 by palucena          #+#    #+#             */
/*   Updated: 2023/10/03 19:00:52 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
