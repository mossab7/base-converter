/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:42:22 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/15 16:56:24 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_convert_base.h"

int	number_lenght(long number, int base_len)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		number = -number;
	while (number > 0)
	{
		len++;
		number /= base_len;
	}
	return (len);
}

char	*itoa_base(long nbr, char *base, int base_len)
{
	int		nbr_len;
	int		is_negative;
	char	*number;

	nbr_len = number_lenght(nbr, base_len);
	is_negative = (nbr < 0);
	number = (char *)malloc((nbr_len + is_negative + 1) * sizeof(char));
	if (!number)
		return (NULL);
	if (is_negative)
	{
		number[0] = '-';
		nbr = -nbr;
	}
	number[nbr_len + is_negative] = '\0';
	if (nbr == 0)
		number[0] = base[0];
	while (nbr > 0)
	{
		number[--nbr_len + is_negative] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_len;
	int		base_to_len;
	long	number;

	if (!base_from || !base_to || !nbr)
		return (NULL);
	base_from_len = valid_base(base_from);
	if (base_from_len < 2)
		return (0);
	base_to_len = valid_base(base_to);
	if (base_to_len < 2)
		return (0);
	number = atoi_base(nbr, base_from, base_from_len);
	return (itoa_base(number, base_to, base_to_len));
}
