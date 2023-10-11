/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/11 15:02:40 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	single_philo(t_philo *ph)
{
	if (ph->cave->max_meals == 0)
		return ;
	sem_wait(ph->cave->forks);
	print_status(ph->cave, ph->index, 'f');
	ft_usleep(ph->cave->t_die);
	print_status(ph->cave, ph->index, 'd');
}

void	*ph_day(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	// En que orden empiezan a comer??
	while (!ph->finished)
	{
		if (ph->cave->max_meals >= 0 && ph->meals >= ph->cave->max_meals)
		{
			ph->finished = true;
			break ;
		}
		r_eat(ph);
		r_sleep(ph);
		r_think(ph);
	}
	return (NULL);
}

void	*ft_own_death(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	while (!ph->finished)
	{
		if (get_time() - ph->last_meal >= ph->cave->t_die)
		{
			print_status(ph->cave, ph->index, 'd');
			break ;
		}
	}
	return (NULL);
}

void	*ft_other_death(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	sem_wait(ph->cave->alive);
	sem_post(ph->cave->alive);
	ph->finished = true;
	return (NULL);
}

void	routine(t_philo *ph)
{
	ph->last_meal = get_time();
	if (ph->cave->n_philo == 1)
	{
		single_philo(ph);
		return ;
	}
	pthread_create(&ph->ph_day, NULL, ph_day, ph);
	pthread_create(&ph->own_death, NULL, ft_own_death, ph);
	pthread_create(&ph->other_death, NULL, ft_other_death, ph);
	sem_wait(ph->cave->alive);
	sem_post(ph->cave->alive);
	pthread_join(ph->ph_day, NULL);
	pthread_join(ph->own_death, NULL);
	pthread_join(ph->other_death, NULL);
	printf("el filosofo %i ha salido\n", ph->index);
	sem_post(ph->cave->waitpid);
	exit(0);
}
