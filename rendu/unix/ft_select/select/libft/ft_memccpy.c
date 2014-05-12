/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 00:11:54 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/24 12:17:52 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{

	if (n != 0)
	{
		*(unsigned char *)s1 = *(unsigned char *)s2;
		if (*(unsigned char *)s2 == (unsigned char)c)
			return (s1 + 1);
		return (ft_memccpy(s1 + 1, s2 + 1, c, --n));
	}
	return (NULL);
}

