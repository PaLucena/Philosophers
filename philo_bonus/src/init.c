/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/13 16:39:13 by palucena         ###   ########.fr       */
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
	if (!c->pid)
		exit (1);
}

void	init_semaphores(t_cave *c)
{
	sem_unlink("alive");
	c->alive = sem_open("alive", O_CREAT, 0600, 0);
	sem_unlink("forks");
	c->forks = sem_open("forks", O_CREAT, 0600, c->n_ph);
	sem_unlink("sem_meal");
	c->sem_meal = sem_open("sem_meal", O_CREAT, 0600, 1);
	sem_unlink("sem_finish");
	c->sem_finish = sem_open("sem_finish", O_CREAT, 0600, 1);
}

void	init_philo(t_cave *c, t_philo *ph, int argc, char **argv)
{
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
