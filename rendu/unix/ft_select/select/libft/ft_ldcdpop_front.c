/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcdpop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 02:35:59 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/09 02:21:26 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_ldcd_cell.h"

void	*ft_ldcdpop_front(t_ldcd ldcd)
{
	void			*elem;
	t_ldcd_cell		temp;
	if (!ldcd || !ldcd->head)
		return (NULL);
	elem = ldcd->head->content;
	if (!ldcd->head->next)
		ldcd->tail = NULL;
	else
		ldcd->head->next->prev = NULL;
	temp = ldcd->head;
	ldcd->head = ldcd->head->next;
	ft_ldcd_celldel(&temp, NULL);
	--(ldcd->size);
	return (elem);
}

