/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:30:29 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/26 18:41:40 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(2, "Syntax: ./client [PID] [MSG]\n", 29), 1);
	if (!send_msg(ft_atoi(av[1]), av[2]))
		return (1);
	return (0);
}
