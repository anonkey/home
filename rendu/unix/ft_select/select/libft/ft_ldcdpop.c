/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcdpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 02:49:06 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/10 03:33:53 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_ldcd_cell.h"

void	*ft_ldcdpop(t_ldcd ldcd, t_ldcd_cell cell)
{
	void			*elem;

	if (!ldcd || !cell)
		return (NULL);
	if (cell->prev == NULL)
		return (ft_ldcdpop_front(ldcd));
	if (cell->next == NULL)
		return (ft_ldcdpop_back(ldcd));
	elem = cell->content;
	cell->prev->next = cell->next;
	cell->next->prev = cell->prev;
	ft_ldcd_celldel(&cell, NULL);
	--(ldcd->size);
	return (elem);
}


