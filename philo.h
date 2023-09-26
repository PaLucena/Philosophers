/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:53 by palucena          #+#    #+#             */
/*   Updated: 2023/09/25 17:28:49 by palucena         ###   ########.fr       */
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
	pthread_t		*philo_id;
	pthread_mutex_t	*fork_id;
	struct s_philo	*philos;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_meals;
	
}	t_cave;

typedef struct s_philo {
	int				index;
	t_cave			*cave;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
}	t_philo;

/*		cycle.c		*/
void	*cycle(void *param);

/*		philo.c		*/
void	filosofar(int ac, char **av);

/*		utils.c		*/
bool	ft_error(int a);
int		ft_atoi(const char *str);
bool	ft_is_number(char *str);

#endif