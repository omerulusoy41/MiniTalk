/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oulusoy <oulusoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:41:25 by oulusoy           #+#    #+#             */
/*   Updated: 2023/02/01 14:03:05 by oulusoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ((str[i] <= 13 && str[i] >= 9) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	ft_putnbr(int num)
{
	int	number_to_write;

	if (num == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		num = 147483648;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
		ft_putnbr(num);
	}
	else
	{
		if (num > 9)
		{
			ft_putnbr(num / 10);
		}
		number_to_write = num % 10 + 48;
		write(1, &number_to_write, 1);
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
