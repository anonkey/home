/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:47:54 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/24 12:24:02 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (*(unsigned char *)s1 == *(unsigned char *)s2)
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
	return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
}

