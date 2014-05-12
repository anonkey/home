/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcddel_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 02:32:26 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/09 00:10:07 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_ldcd_cell.h"

void	ft_ldcddel_tail(t_ldcd ldcd)
{
	t_ldcd_cell		temp;

	if (!ldcd || !ldcd->tail)
		return ;
	if (!ldcd->tail->prev)
		ldcd->head = NULL;
	else
		ldcd->tail->prev->next = NULL;
	temp = ldcd->tail;
	ldcd->tail = ldcd->tail->prev;
	ft_ldcd_celldel(&temp, ft_memdel);
	--(ldcd->size);
}

