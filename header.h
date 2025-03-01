/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:30:08 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/01 16:46:03 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define I SIGUSR1
# define O SIGUSR2

int		send_msg(pid_t pid, char *msg);
long	ft_atoi(const char *nptr);
void	ft_putnbr(int n);

#endif
