/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/10/11 16:20:58 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ph_life(t_cave *c)
{
	int	i;

	i = 0;
	while (i < c->n_philo)
	{
		c->pid[i] = fork();
		if (c->pid[i] == 0)
		{
			c->ph[i].t_start = get_time();
			routine(&c->ph[i]);
			break ;
		}
		i++;
	}
}
