/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:53 by palucena          #+#    #+#             */
/*   Updated: 2023/12/01 09:12:22 by palucena         ###   ########.fr       */
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

typedef struct s_cave
{
	int		n_ph;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	pid_t	*pid;
	sem_t	*forks;
	sem_t	*write;
	sem_t	*init;
	sem_t	*time;
	sem_t	*death;
}	t_cave;

typedef struct s_philo
{
	bool		lock;
	int			index;
	bool		finished;
	t_cave		*cave;
	long		t_start;
	long		t_last_meal;
	int			meals_left;
}	t_philo;

/*------init.c---------*/
void	init_struct(t_cave *c, t_philo *ph, int argc, char **argv);

/*------life.c---------*/
void	ph_life(t_cave *c, t_philo *ph);
void	single_philo(t_philo *ph);
void	*ft_routine(void *param);

/*------routine.c------*/
void	ft_philo(t_philo *ph);

/*------day.c----------*/
void	ft_die(t_philo *ph);
void	r_think(t_philo *ph);
void	r_sleep(t_philo *ph);
void	r_eat(t_philo *ph);

/*------print.c--------*/
void	print_status(t_philo *ph, char a);

/*------death.c--------*/
void	kill_them(t_cave *c);
void	ph_death(t_cave *c);

/*------utils.c--------*/
long	ft_atol(const char *str);
bool	ft_is_number(char *str);
long	get_time(void);
void	ft_usleep(long time, t_philo *ph);

#endif