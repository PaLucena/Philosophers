/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:19:53 by palucena          #+#    #+#             */
/*   Updated: 2023/10/09 12:32:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*select_s(char s)
{
	if (s == 'f')
		return ("has taken a fork");
	else if (s == 'e')
		return ("is eating");
	else if (s == 's')
		return ("is sleeping");
	else if (s == 't')
		return ("is thinking");
	else if (s == 'd')
		return ("died");
	return (NULL);
}

void	print_status(t_cave *cave, int index, char s)
{
	pthread_mutex_lock(cave->write);
	pthread_mutex_lock(cave->life);
	if (cave->vivos)
	{
		printf("%ld %i %s\n", get_time() - cave->t_start, index, select_s(s));
		if (s == 'd')
			cave->vivos = false;
	}
	pthread_mutex_unlock(cave->life);
	pthread_mutex_unlock(cave->write);
}
