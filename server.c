/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:29:24 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/26 19:04:54 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handler(int sig)
{
	int	bit;
	char c;

	bit = 7;
	while(bit--)
	{
		if(sig == I)
			c &= 1;
		else
			c <<= 1;
		c <<= 1;
	}
	write(1, &c, 1);
}
int	main()
{	
	signal(I, handler);
	signal(O, handler);
	printf("test: %d\n", getpid());
	while(1){}
}
