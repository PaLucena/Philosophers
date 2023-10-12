/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/12 17:41:02 by palucena         ###   ########.fr       */
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
	if (ph->index > ph->cave->n_ph / 2)
		print_status(ph->cave, ph->index, 't');
	while (1)
	{
		sem_wait(ph->cave->sem_finish);
		if (ph->finished)
			break ;
		sem_post(ph->cave->sem_finish);
		if (ph->cave->max_meals >= 0 && ph->meals == ph->cave->max_meals)
			sem_post(ph->cave->all_full);
		r_eat(ph);
		r_sleep(ph);
		r_think(ph);
	}
	sem_post(ph->cave->sem_finish);
	return (NULL);
}

void	*ft_own_death(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	while (!ph->finished)
	{
		/* sem_wait(ph->cave->sem_finish);
		if (ph->finished)
			break ;
		sem_post(ph->cave->sem_finish); */
		sem_wait(ph->cave->sem_meal);
		if (get_time() - ph->last_meal >= ph->cave->t_die)
		{
			print_status(ph->cave, ph->index, 'd');
			sem_post(ph->cave->sem_meal);
			break ;
		}
		else
			sem_post(ph->cave->sem_meal);
	}
	return (NULL);
}

void	*ft_other_death(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	sem_wait(ph->cave->alive);
	sem_post(ph->cave->alive);
	sem_wait(ph->cave->sem_finish);
	ph->finished = true;
	sem_post(ph->cave->sem_finish);
	return (NULL);
}

void	routine(t_philo *ph)
{
	ph->last_meal = get_time();
	if (ph->cave->n_ph == 1 || ph->cave->max_meals == 0)
	{
		single_philo(ph);
		sem_post(ph->cave->all_full);
		exit(0);
	}
	pthread_create(&ph->ph_day, NULL, ph_day, ph);
	pthread_create(&ph->own_death, NULL, ft_own_death, ph);
	pthread_create(&ph->other_death, NULL, ft_other_death, ph);
	sem_wait(ph->cave->alive);
	sem_post(ph->cave->alive);
	pthread_join(ph->ph_day, NULL);
	pthread_join(ph->own_death, NULL);
	pthread_join(ph->other_death, NULL);
	//printf("el filosofo %i ha salido\n", ph->index);
	sem_post(ph->cave->all_full);
	exit(0);
}
