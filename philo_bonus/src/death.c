/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:18 by palucena          #+#    #+#             */
/*   Updated: 2023/10/14 20:39:53 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	kill_them(t_cave *c)
{
	int	i;

	i = -1;
	while (++i < c->n_ph)
		kill(c->pid[i], SIGKILL);
}

void	ph_death(t_cave *c)
{
	sem_close(c->forks);
	sem_unlink("forks");
	sem_close(c->write);
	sem_unlink("write");
	free(c->pid);
	printf("Final del proceso padre\n");
}
