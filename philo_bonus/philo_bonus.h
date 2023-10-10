/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:53 by palucena          #+#    #+#             */
/*   Updated: 2023/10/10 16:38:54 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <pthread.h>
# include <stdbool.h>
# include <semaphore.h>
# include <signal.h>

struct	s_philo;

typedef struct s_cave {
	int				n_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				max_meals;
	pid_t			*pid;
	struct s_philo	*ph;
	sem_t			*alive;
	sem_t			*forks;
	sem_t			*waitpid;
	sem_t			*race_death;
}	t_cave;

typedef struct s_philo {
	int			index;
	bool		finished;
	t_cave		*cave;
	long		t_start;
	long		last_meal;
	int			meals;
	pthread_t	ph_day;
	pthread_t	own_death;
	pthread_t	other_death;
}	t_philo;

/*------init.c---------*/
t_cave	*init_struct(int argc, char **argv);

/*------life.c---------*/
void	ph_life(t_cave *c);

/*------routine.c------*/
void	routine(t_philo *ph);

/*------day.c----------*/
void	r_think(t_philo *ph);
void	r_sleep(t_philo *ph);
void	r_eat(t_philo *ph);

/*------print.c--------*/
void	print_status(t_cave *c, int i, char a);

/*------death.c--------*/
void	ph_death(t_cave *c);

/*------utils.c--------*/
long	ft_atol(const char *str);
bool	ft_is_number(char *str);
long	get_time(void);
void	ft_usleep(long time);

#endif