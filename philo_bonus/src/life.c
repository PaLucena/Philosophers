/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/12/01 09:11:51 by palucena         ###   ########.fr       */
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

void	single_philo(t_philo *ph)
{
	if (ph->meals_left == 0)
		exit (0);
	sem_wait(ph->cave->forks);
	print_status(ph, 'f');
	ft_usleep(ph->cave->t_die, ph);
	print_status(ph, 'd');
}

void	*ft_routine(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	if (ph->index > ph->cave->n_ph / 2)
		print_status(ph, 't');
	while (1)
	{
		if (ph->meals_left == 0)
			exit (0);
		r_eat(ph);
		r_sleep(ph);
		r_think(ph);
	}
	return (NULL);
}
