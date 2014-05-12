/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcdpush_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 04:26:38 by tseguier          #+#    #+#             */
/*   Updated: 2013/12/04 05:08:12 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ldcd_cell.h"
#include "libft.h"

int		ft_ldcdpush_front(t_ldcd ldcd, void *elem, size_t elem_size)
{
	t_ldcd_cell		temp;

	if (!ldcd)
		return (-1);
	temp = t_ldcd_cellnew(elem, elem_size);
	if (!temp)
		return (-1);
	temp->next = ldcd->head;
	ldcd->head = temp;
	if (!temp->next)
		ldcd->tail = temp;
	else
		temp->next->prev = temp;
	++(ldcd->size);
	return (1);
}

