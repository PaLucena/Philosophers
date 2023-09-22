/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:59 by palucena          #+#    #+#             */
/*   Updated: 2023/09/22 11:40:21 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	hilo(void)
{
	pthread_t	thread_id;

	pthread_create(&thread_id, NULL, ft_start, arg);1
}
