/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:21:27 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/09 12:36:00 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_convert_base.h"
int	find_index(char *base, char digit)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (digit == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

long	atoi_base(char *str, char *base, int len)
{
	long	result;
	int		sign;
	int		i;
	int		index;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		index = find_index(base, str[i++]);
		if (index == -1)
			return (result * sign);
		result = result * len + index;
	}
	return (result * sign);
}
