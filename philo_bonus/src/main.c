/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:20 by palucena          #+#    #+#             */
/*   Updated: 2023/10/13 11:56:53 by palucena         ###   ########.fr       */
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
	int		status;

	//atexit(ft_leaks);
	if ((argc != 5 && argc != 6) || !check_args(argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	c = init_struct(argc, argv);
	ph_life(c);
	i = -1;
	while (++i < c->n_ph)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
			kill(c->pid[i], SIGKILL);
	}		
	ph_death(c);
	return (0);
}
