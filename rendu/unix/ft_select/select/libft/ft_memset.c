/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:41:25 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/27 17:12:51 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void		ft_charmemset(unsigned char *b, unsigned char c, size_t len)
{
	if (len > 0 && b)
	{
		*b = c;
		ft_charmemset(++b, c, --len);
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	if (len > 0 && b)
		ft_charmemset((unsigned char *)b, (unsigned char)c, len);
	return (b);
}

