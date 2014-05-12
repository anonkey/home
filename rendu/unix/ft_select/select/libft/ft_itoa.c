/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:22:49 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/27 17:10:33 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static size_t	ft_compute_nbsize(int nb)
{
	if (nb / 10 == 0)
	return (1);
	return (1 + ft_compute_nbsize(nb / 10));
}

char			*ft_itoa(int n)
{
	size_t	size;
	int		neg;
	char	*nbstr;

	neg = (n < 0) ? 1 : 0;
	size = neg + ft_compute_nbsize(n);
	nbstr = ft_strnew(size);
	if (!nbstr)
		return (NULL);
	if (neg == 1)
		nbstr[0] = '-';
	while (size-- > (size_t)neg)
	{
		nbstr[size] = '0' + (char)((neg) ? (0 - n % 10) : (n % 10));
		n /= 10;
	}
	return (nbstr);
}

