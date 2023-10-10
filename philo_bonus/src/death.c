/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:36:18 by palucena          #+#    #+#             */
/*   Updated: 2023/10/10 13:41:00 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ph_death(t_cave *c)
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
}
