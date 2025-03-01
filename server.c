/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:29:24 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/01 16:13:11 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	action(int sig, siginfo_t *siginfo, void *ucontext)
{
	static int		bit;
	static char		c;
	static pid_t	pid;

	(void)ucontext;
	if (pid == 0 || pid != siginfo->si_pid)
	{
		bit = 0;
		c = 0;
		pid = siginfo->si_pid;
	}
	c |= (sig == I);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			kill(pid, I);
		write(1, &c, 1);
		bit = 0;
		c = 0;
		pid = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(I, &sa, NULL) == -1 || sigaction(O, &sa, NULL) == -1)
		exit(1);
	while (1)
		pause();
}
