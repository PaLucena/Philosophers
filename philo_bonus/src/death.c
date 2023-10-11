/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:18 by palucena          #+#    #+#             */
/*   Updated: 2023/10/11 15:53:09 by palucena         ###   ########.fr       */
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

void	ph_death(t_cave *c)
{
	int	i;
	int status;

	i = 0;
	sem_close(c->alive);
	sem_unlink("alive");
	sem_close(c->forks);
	sem_unlink("forks");
	sem_close(c->waitpid);
	sem_unlink("waitpid");
	sem_close(c->race_death);
	sem_unlink("race_death");
	sem_close(c->write);
	sem_unlink("write");
	while (++i <= c->n_philo)
		waitpid(c->pid[i], &status, 0);
	free(c->pid);
	free(c->ph);
	//free(c);
	printf("Final del proceso padre\n");
}
