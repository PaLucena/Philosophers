/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:53 by palucena          #+#    #+#             */
/*   Updated: 2023/09/26 16:02:34 by palucena         ###   ########.fr       */
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

struct s_philo;

typedef struct s_cave {
	bool			vivos;
	pthread_t		*philo_id;
	pthread_mutex_t	*fork_id;
	pthread_mutex_t	*write;
	struct s_philo	*philos;
	int				n_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				n_of_meals;
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

/*		actions.c	*/
int	ft_eat(t_philo *plato);
int	ft_sleep(t_philo *plato);
int	ft_think(t_philo *plato);

/*		cycle.c		*/
long	ft_time(void);
void	*cycle(void *param);

/*		philo.c		*/
void	filosofar(int ac, char **av);

/*		utils.c		*/
bool	ft_error(int a);
int		ft_atoi(const char *str);
bool	ft_is_number(char *str);
bool	check_status(t_cave *cueva);

#endif