/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:43:39 by palucena          #+#    #+#             */
/*   Updated: 2023/12/06 16:31:27 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	own_semaphore(t_philo *ph, int mode)
{
	char	str[2];

	str[0] = (char)ph->index;
	str[1] = '\0';
	sem_unlink(str);
	if (mode == 1)
		ph->shield = sem_open(str, O_CREAT, S_IRWXU, 1);
	else if (mode == 2)
		sem_close(ph->shield);
}

long	ft_atol(const char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

bool	ft_is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
	}
	return (true);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(long time)
{
	long	end;

	end = get_time() + time;
	while (1)
	{
		if (end == get_time())
			break ;
	}
}
