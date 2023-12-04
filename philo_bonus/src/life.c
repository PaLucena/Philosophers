/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/12/04 16:59:45 by palucena         ###   ########.fr       */
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
			own_semaphore(ph, 1);
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
	else if (ph->meals_left == 0)
	{
		ph->lock = true;
		return (NULL);
	}
	while (1)
	{
		if (r_eat(ph) == 0)
			sem_post(ph->cave->init);
		if (ph->lock)
			break ;
		r_sleep(ph);
		r_think(ph);
	}
	return (NULL);
}
