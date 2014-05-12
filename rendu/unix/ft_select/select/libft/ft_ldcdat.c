/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcdat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:50:16 by tseguier          #+#    #+#             */
/*   Updated: 2013/12/06 01:33:47 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"


size_t		ft_ldcdat(t_ldcd ldcd, const void **at, unsigned int i)
{
	t_ldcd_cell		iter;
	unsigned int	j;

	if (!ldcd || !at || i >= ldcd->size)
	{
		if (at)
			*at = NULL;
		return (0);
	}
	iter = (i < (unsigned int)ldcd->size / 2) ? ldcd->head : ldcd->tail;
	j = (i < (unsigned int)ldcd->size / 2) ? 0 : (ldcd->size - 1);
	if (iter == ldcd->head)
	{
		while (j++ < i)
			iter = iter->next;
	}
	else
	{
		while (j-- > i)
			iter = iter->prev;
	}
	*at = iter->content;
	return (iter->content_size);
}

