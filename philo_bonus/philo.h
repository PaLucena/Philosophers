/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:53 by palucena          #+#    #+#             */
/*   Updated: 2023/10/09 01:03:11 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <pthread.h>
# include <stdbool.h>
# include <semaphore.h>
#include <signal.h>

struct	s_philo;

typedef struct s_cave {
	int				n_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	pid_t			*pid;
	sem_t			*alive;
	sem_t			*race_death;
	sem_t			*all_eaten;
	sem_t			*all_finished;
	sem_t			*forks;
	pthread_t		food;
	int				max_meals;
	struct s_philo	*philos;
}	t_cave;

typedef struct s_philo {
	int				index;
	t_cave			*cave;
	long			t_start;
	long			last_meal;
	int				meals;
	pthread_t		self_death;
	pthread_t		routine;
}	t_philo;

/*		cycle.c		*/
void	ft_philo(t_philo *plato);

/*		init.c		*/
t_cave	*init_cave(int ac, char **av);
void	init_philo(t_cave *cave);

/*		philo.c		*/
void	filosofar(int ac, char **av);

/*		utils.c		*/
long	ft_atol(const char *str);
bool	ft_is_number(char *str);
long	get_time(void);
void	ft_usleep(int time);

#endif