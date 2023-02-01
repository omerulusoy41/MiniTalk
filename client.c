/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oulusoy <oulusoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:39:15 by oulusoy           #+#    #+#             */
/*   Updated: 2023/02/01 13:56:57 by oulusoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int say, int pid, char *str)
{
	while (--say >= 0)
	{
		if ((*str & (1 << say)) != 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argcount, char **args)
{
	int	i;
	int	pid;

	if (argcount != 3)
		write(1, "args must be =>./a.out pid \"string\"", 35);
	else
	{
		i = -1;
		pid = ft_atoi(args[1]);
		while (++i < ft_strlen(args[2]))
			send(8, pid, &args[2][i]);
	}
	return (0);
}
