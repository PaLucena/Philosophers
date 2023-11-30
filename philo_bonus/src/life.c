/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/11/30 17:13:13 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ph_life(t_cave *c, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < c->n_ph)
	{
		c->pid[i] = fork();
		if (c->pid[i] == 0)
		{
			ph->index = i + 1;
			ph->t_start = get_time();
			ft_philo(ph);
		}
		i++;
	}
}
