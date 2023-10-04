/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:53 by palucena          #+#    #+#             */
/*   Updated: 2023/10/04 23:47:14 by palucena         ###   ########.fr       */
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
	sem_t			*alive;
	sem_t			*all_eaten;
	sem_t			*forks;
	pid_t			*philo_id;
	pthread_t		death;
	pthread_t		food;
	struct s_philo	*philos;
	int				n_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				max_meals;
	long			set_time;
}	t_cave;

typedef struct s_philo {
	int				index;
	t_cave			*cave;
	long			last_meal;
	int				meals;
	pthread_t		self_death;
	sem_t			*sem_death;
}	t_philo;

/*		cycle.c		*/
void	routine(t_philo *plato);

/*		init.c		*/
t_cave	*init_cave(int ac, char **av);
void	init_philo(t_cave *cave);

/*		philo.c		*/
void	filosofar(int ac, char **av);

/*		utils.c		*/
bool	ft_is_number(char *str);
long	get_time(void);
void	ft_usleep(int time);

/*		utils2.c	*/
char	*ft_itoa(int n);
long	ft_atol(const char *str);

#endif