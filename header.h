/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:30:08 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/26 18:53:09 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define	HEADER_H

#include <stdio.h>
#include <stdlib.h>


#include <unistd.h>
#include <signal.h>

#define I SIGUSR1
#define O SIGUSR2

int	send_msg(pid_t	pid, char *msg);
long	ft_atoi(const char *nptr);

#endif
