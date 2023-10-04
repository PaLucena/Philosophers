/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:08:31 by palucena          #+#    #+#             */
/*   Updated: 2023/10/04 23:26:59 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_count(long int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	n2;
	char		*n_char;

	n2 = n;
	if (n2 < 0)
		n2 *= -1;
	len = ft_count(n2);
	if (n < 0)
		len++;
	n_char = malloc(sizeof(char) * (len + 1));
	if (!n_char)
		return (0);
	n_char[len--] = 0;
	while (len >= 0)
	{
		n_char[len--] = (n2 % 10) + '0';
		n2 /= 10;
	}
	if (n < 0)
		n_char[0] = '-';
	return (n_char);
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
