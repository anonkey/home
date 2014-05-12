/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcdpop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 02:10:39 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/09 02:21:12 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_ldcd_cell.h"

void	*ft_ldcdpop_back(t_ldcd ldcd)
{
	void			*elem;
	t_ldcd_cell		temp;

	if (!ldcd || !ldcd->tail)
		return (NULL);
	elem = ldcd->tail->content;
	if (!ldcd->tail->prev)
		ldcd->head = NULL;
	else
		ldcd->tail->prev->next = NULL;
	temp = ldcd->tail;
	ldcd->tail = ldcd->tail->prev;
	ft_ldcd_celldel(&temp, NULL);
	--(ldcd->size);
	return (elem);
}

