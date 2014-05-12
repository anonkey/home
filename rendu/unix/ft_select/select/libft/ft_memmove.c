/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:53:54 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/27 18:08:00 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (n == 0 || s1 == s2)
		return (s1);
	if (s2 < s1 && s2 + n > s1)
	{
		while (n > 0)
		{
			((unsigned char *)s1)[n - 1] = ((unsigned char *)s2)[n - 1];
			--n;
		}
	}
	else
	{
		ft_memcpy(s1, s2, n);
	}
	return (s1);
}

