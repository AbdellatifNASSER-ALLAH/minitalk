/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:29:24 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/18 16:50:37 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handler(int sig)
{
	(void)sig;
	write(1, "what r u doing buddy!!\n", 23);
}
int	main()
{	
	signal(SIGINT, handler);
	printf("test: %d\n", getpid());
	while(1){}
}
