/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:51 by palucena          #+#    #+#             */
/*   Updated: 2023/10/10 17:12:20 by palucena         ###   ########.fr       */
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
		printf("\n%i\n\n", ph->index);
	}
//	printf("%i Cierra h3\n", ph->index);
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
//	printf("%i Cierra h1\n", ph->index);
	return (NULL);
}

void	*ft_other_death(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	sem_wait(ph->cave->alive);
	sem_post(ph->cave->alive);
	ph->finished = true;
//	printf("%i Cierra h2\n", ph->index);
	return (NULL);
}

void	routine(t_philo *ph)
{
//	printf("%i Start ----------------------------------\n", ph->index);
	ph->last_meal = get_time();
	if (ph->cave->n_philo == 1)
	{
		single_philo(ph);
		return ;
	}
	pthread_create(&ph->ph_day, NULL, ph_day, ph);
	pthread_create(&ph->own_death, NULL, ft_own_death, ph);
	pthread_create(&ph->other_death, NULL, ft_other_death, ph);
	/* while (1)
	{
		if (ph->finished)
			break ;
	} */
	sem_wait(ph->cave->alive);
	sem_post(ph->cave->alive);
	pthread_join(ph->ph_day, NULL);
	pthread_join(ph->own_death, NULL);
	pthread_join(ph->other_death, NULL);
	sem_post(ph->cave->waitpid);
	printf("sale %i\n", ph->index);
	return ;
}
