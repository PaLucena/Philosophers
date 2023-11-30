/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:51 by palucena          #+#    #+#             */
/*   Updated: 2023/11/30 17:12:53 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	init_cave(t_cave *c, char **argv)
{
	c->n_ph = ft_atol(argv[1]);
	c->t_die = (ft_atol(argv[2]));
	c->t_eat = (ft_atol(argv[3]));
	c->t_sleep = (ft_atol(argv[4]));
	c->pid = malloc(sizeof(pid_t) * c->n_ph);
}

void	init_semaphores(t_cave *c)
{
	sem_unlink("forks");
	c->forks = sem_open("forks", O_CREAT, 0600, c->n_ph);
	sem_unlink("write");
	c->write = sem_open("write", O_CREAT, 0600, 1);
	sem_unlink("init");
	c->init = sem_open("init", O_CREAT, 0600, 0);
	sem_unlink("death");
	c->death = sem_open("death", O_CREAT, 0600, 0);
}

void	init_philo(t_cave *c, t_philo *ph, int argc, char **argv)
{
	ph->lock = false;
	ph->index = 0;
	ph->finished = false;
	if (argc == 6)
		ph->meals_left = ft_atol(argv[5]);
	else
		ph->meals_left = -1;
	ph->cave = c;
}

void	init_struct(t_cave *c, t_philo *ph, int argc, char **argv)
{
	init_cave(c, argv);
	init_semaphores(c);
	init_philo(c, ph, argc, argv);
}
