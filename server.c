/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oulusoy <oulusoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:33:30 by oulusoy           #+#    #+#             */
/*   Updated: 2023/02/01 14:05:53 by oulusoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_say = 7;

void	add_char(int s)
{
	static char	msg;

	if (s == SIGUSR2)
		msg |= 1 << g_say;
	g_say --;
	if (g_say == -1)
	{
		write(1, &msg, 1);
		g_say = 7;
		msg = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, add_char);
	signal(SIGUSR2, add_char);
	ft_putnbr((int)(getpid()));
	write(1, "\n", 1);
	while (1)
	{
	}
}
