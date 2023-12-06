/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:20 by palucena          #+#    #+#             */
/*   Updated: 2023/12/06 16:49:32 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ph_death(t_cave *c)
{
	int	status;
	int	i;

	i = 0;
	while (++i <= c->n_ph)
	{
		waitpid(-1, &status, 0);
		if (status)
		{
			i = -1;
			while (++i < c->n_ph)
				kill(c->pid[i], SIGTERM);
		}
	}
	sem_close(c->forks);
	sem_unlink("forks");
	sem_close(c->write);
	sem_unlink("write");
	sem_close(c->d_lock);
	sem_unlink("d_lock");
	sem_close(c->death);
	sem_unlink("death");
	free(c->pid);
}

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

int	main(int argc, char **argv)
{
	t_cave	c;
	t_philo	ph;

	if ((argc != 5 && argc != 6) || !check_args(argc, argv))
	{
		printf("\033[31;1mError\n");
		return (1);
	}
	init_struct(&c, &ph, argc, argv);
	ph_life(&c, &ph);
	ph_death(&c);
	return (0);
}
