/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/13 12:42:02 by palucena         ###   ########.fr       */
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
		ft_usleep(1000);
	//	print_status(ph->cave, ph->index, 't');
	while (1)
	{
		if (ft_die(ph))
			break ;
		if (ph->cave->max_meals >= 0 && ph->meals == ph->cave->max_meals)
			sem_post(ph->cave->all_full);
		if (!ft_die(ph))
			r_eat(ph);
		if (!ft_die(ph))
			r_sleep(ph);
		if (!ft_die(ph))
			r_think(ph);
	}
	sem_post(ph->cave->sem_finish);
	return (NULL);
}

void	*ft_some_death(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	sem_wait(ph->cave->alive);
	sem_post(ph->cave->alive);
	sem_wait(ph->cave->sem_finish);
	ph->finished = true;
	printf("---------------------------Ahora manda la señal para parar\n");
	sem_post(ph->cave->sem_finish);
	return (NULL);
}

void	routine(t_philo *ph)
{
	ph->t_last_meal = get_time();
	if (ph->cave->n_ph == 1 || ph->cave->max_meals == 0)
	{
		single_philo(ph);
		sem_post(ph->cave->all_full);
		exit(0);
	}
	pthread_create(&ph->ph_day, NULL, ph_day, ph);
	pthread_create(&ph->some_death, NULL, ft_some_death, ph);
	sem_wait(ph->cave->alive);
	sem_post(ph->cave->alive);
	pthread_join(ph->ph_day, NULL);
	pthread_join(ph->some_death, NULL);
	sem_post(ph->cave->all_full);
	exit(0);
}
