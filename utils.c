/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:21:06 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/27 11:20:53 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

static	void send_char(pid_t pid, char c)
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
		usleep(50);
	}
}

int	send_msg(pid_t	pid, char *msg)
{
	if (kill(pid, 0) == -1)
		return (write(2, "Process Not found!\n", 19), 0);
	while(*msg)
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
	while (*nptr && *nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*nptr++ - 48);
	return (res * sign);
}
