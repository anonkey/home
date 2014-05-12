/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcddel_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 02:29:23 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/09 00:09:52 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_ldcd_cell.h"

void	ft_ldcddel_head(t_ldcd ldcd)
{
	t_ldcd_cell		temp;

	if (!ldcd || !ldcd->head)
		return ;
	if (!ldcd->head->next)
		ldcd->tail = NULL;
	else
		ldcd->head->next->prev = NULL;
	temp = ldcd->head;
	ldcd->head = ldcd->head->next;
	ft_ldcd_celldel(&temp, ft_memdel);
	--(ldcd->size);
}

