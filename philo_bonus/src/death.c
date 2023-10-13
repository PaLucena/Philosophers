/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:18 by palucena          #+#    #+#             */
/*   Updated: 2023/10/13 16:39:19 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

/* void	ph_death(t_cave *c)
{
	sem_close(c->alive);
	sem_unlink("alive");
	sem_close(c->forks);
	sem_unlink("forks");
	sem_close(c->waitpid);
	sem_unlink("waitpid");
	sem_close(c->race_death);
	sem_unlink("race_death");
	free(c->pid);
	free(c->ph);
	//free(c);
	printf("Final del proceso padre\n");
} */

void	kill_them(t_cave *c)
{
	int	i;

	i = -1;
	while (++i < c->n_ph)
		kill(c->pid[i], SIGKILL);
}

void	ph_death(t_cave *c)
{
	sem_close(c->alive);
	sem_unlink("alive");
	sem_close(c->forks);
	sem_unlink("forks");
	sem_close(c->sem_meal);
	sem_unlink("sem_meal");
	sem_close(c->sem_finish);
	sem_unlink("sem_finish");
	free(c->pid);
	printf("Final del proceso padre\n");
}
