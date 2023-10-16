/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:19:53 by palucena          #+#    #+#             */
/*   Updated: 2023/10/16 22:36:48 by palucena         ###   ########.fr       */
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

void	print_status(t_philo *ph, char a)
{
	sem_wait(ph->cave->write);
	printf("%ld %i %s\n", get_time() - ph->t_start, ph->index, sel_a(a));
	if (a == 'd')
		exit (1);
	else
		sem_post(ph->cave->write);
}
