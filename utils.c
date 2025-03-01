/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:21:06 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/01 16:39:55 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

static void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (c & 0x80)
			kill(pid, I);
		else
			kill(pid, O);
		c <<= 1;
		usleep(500);
	}
}

int	send_msg(pid_t pid, char *msg)
{
	if (pid == -1 || kill(pid, 0) == -1)
		return (0);
	while (*msg)
		send_char(pid, *(msg++));
	send_char(pid, *msg);
	return (1);
}

long	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (!(*nptr && *nptr >= '0' && *nptr <= '9'))
		return (-1);
	while (*nptr && *nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*nptr++ - 48);
	if (*nptr && !(*nptr && *nptr >= '0' && *nptr <= '9'))
		return (-1);
	return (res * sign);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		c = (n % 10) + 48;
		write(1, &c, 1);
	}
}
