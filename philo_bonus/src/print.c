/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:19:53 by palucena          #+#    #+#             */
/*   Updated: 2023/10/12 18:03:12 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

char	*sel_a(char a)
{
	if (a == 'f')
		return ("has taken a fork");
	else if (a == 'e')
		return ("is eating");
	else if (a == 's')
		return ("is sleeping");
	else if (a == 't')
		return ("is thinking");
	else if (a == 'd')
		return ("died");
	return (NULL);
}

void	print_status(t_cave *c, int i, char a)
{
	sem_wait(c->sem_finish);
	if (!c->ph[i - 1].finished)
		printf("%ld %i %s\n", get_time() - c->ph[i - 1].t_start, i, sel_a(a));
	sem_post(c->sem_finish);
	if (a == 'd')
	{
		printf("---------------------------Ya deberia parar\n");
		sem_wait(c->sem_finish);
		c->ph[i - 1].finished = true;
		sem_post(c->sem_finish);
		sem_post(c->alive);
	}
}
