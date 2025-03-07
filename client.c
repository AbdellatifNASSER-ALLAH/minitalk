/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:30:29 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/01 15:59:49 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handler(int sig)
{
	(void)sig;
	write(1, "Message recived!\n", 17);
}

int	main(int ac, char **av)
{
	signal(I, handler);
	if (ac != 3)
		return (write(2, "Syntax: ./client [PID] [MSG]\n", 29), 1);
	if (!send_msg(ft_atoi(av[1]), av[2]))
		return (write(2, "Process Not found!\n", 19), 0);
	return (0);
}
