/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 03:27:42 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/30 20:38:05 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

long	ft_atol(const char *str)
{
	long		number;
	long		sign;

	number = 0;
	if (ft_strncmp(str, "-9223372036854775808", 20) == 0
		&& (str[20] < '0' || str[20] > '9'))
		return (-9223372036854775807 - 1);

	while (ft_isspace(*str))
		++str;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += (long)*str - 48;
		++str;
		if (number < 0)
			return (-1);
	}
	return (number * sign);
}

int		ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}

