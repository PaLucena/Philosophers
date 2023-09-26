/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/09/26 16:15:16 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*cycle(void *param)
{
	t_philo	*plato;

	plato = (t_philo *)param;
	while (plato->cave->vivos)
	{
		ft_eat(plato);
		ft_sleep(plato);
		ft_think(plato);
	}
	return (NULL);
}
