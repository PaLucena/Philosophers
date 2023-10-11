/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/11 15:00:25 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_cave	*init_cave(int argc, char **argv)
{
	t_cave	*c;

	c = malloc(sizeof(t_cave));
	if (!c)
		exit (1);
	c->n_philo = ft_atol(argv[1]);
	c->t_die = (ft_atol(argv[2]));
	c->t_eat = (ft_atol(argv[3]));
	c->t_sleep = (ft_atol(argv[4]));
	if (argc == 6)
		c->max_meals = ft_atol(argv[5]);
	else
		c->max_meals = -1;
	c->pid = malloc(sizeof(pid_t) * c->n_philo);
	c->ph = malloc(sizeof(t_philo) * c->n_philo);
	if (!c->pid || !c->ph)
		exit (1);
	return (c);
}

void	init_semaphores(t_cave *c)
{
	sem_unlink("alive");
	c->alive = sem_open("alive", O_CREAT, 0600, 0);
	sem_unlink("forks");
	c->forks = sem_open("forks", O_CREAT, 0600, c->n_philo);
	sem_unlink("race_death");
	c->race_death = sem_open("race_death", O_CREAT, 0600, 1);
	sem_unlink("waitpid");
	c->waitpid = sem_open("waitpid", O_CREAT, 0600, 0);
	sem_unlink("write");
	c->write = sem_open("write", O_CREAT, 0600, 1);
}

void	init_philo(t_cave *c)
{
	int		i;

	i = -1;
	while (++i < c->n_philo)
	{
		c->ph[i].index = i + 1;
		c->ph[i].finished = false;
		c->ph[i].meals = 0;
		c->ph[i].cave = c;
	}
}

t_cave	*init_struct(int argc, char **argv)
{
	t_cave	*c;

	//c = malloc(sizeof(t_cave *));
	/* if (!c)
		exit (1); */
	c = init_cave(argc, argv);
	init_semaphores(c);
	init_philo(c);
	return (c);
}
