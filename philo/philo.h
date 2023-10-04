/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:53 by palucena          #+#    #+#             */
/*   Updated: 2023/10/04 20:51:33 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

struct	s_philo;

typedef struct s_cave {
	bool			vivos;
	bool			all_eaten;
	pthread_mutex_t	*life;
	pthread_t		*philo_id;
	pthread_mutex_t	*fork_id;
	pthread_mutex_t	*write;
	pthread_mutex_t	*meal;
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
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	long			last_meal;
	int				meals;
}	t_philo;

/*		check.c		*/
bool	check_args(char **av, int ac);
int		check_status(t_cave *cave);

/*		cycle.c		*/
void	print_status(t_cave *cave, int index, char status);
void	*cycle(void *param);

/*		init.c		*/
t_cave	*init_cave(int ac, char **av);
void	init_philo(t_cave *cave);

/*		philo.c		*/
void	ft_life(t_cave *cave);
void	ft_afterlife(t_cave *cave);

/*		utils.c		*/
long	ft_atol(const char *str);
bool	ft_is_number(char *str);
long	get_time(void);
void	ft_usleep(int time);

#endif