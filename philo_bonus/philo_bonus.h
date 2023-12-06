/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:53 by palucena          #+#    #+#             */
/*   Updated: 2023/12/06 19:44:37 by palucena         ###   ########.fr       */
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
	long	borrar;
	long	t_eat;
	long	t_sleep;
	pid_t	*pid;
	sem_t	*forks;
	sem_t	*write;
	sem_t	*d_lock;
	sem_t	*shield;
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
	sem_t		*shield;
}	t_philo;

/*------init.c---------*/
void	init_struct(t_cave *c, t_philo *ph, int argc, char **argv);

/*------routine.c------*/
void	ph_life(t_cave *c, t_philo *ph);
void	ft_philo(t_philo *ph);

/*------routine.c----------*/
void	r_think(t_philo *ph, bool d);
void	r_sleep(t_philo *ph);
int		r_eat(t_philo *ph);
void	single_philo(t_philo *ph);
void	*ft_routine(void *param);

/*------print.c--------*/
void	print_status(t_philo *ph, char a);

/*------utils.c--------*/
void	own_semaphore(t_philo *ph, int mode);
long	ft_atol(const char *str);
bool	ft_is_number(char *str);
long	get_time(void);
void	ft_usleep(long time);

#endif