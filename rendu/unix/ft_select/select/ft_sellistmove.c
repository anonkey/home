/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sellistmove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 00:25:17 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/12 08:45:03 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sellist.h"
#include "libft.h"


void	ft_getnextelem(t_ldcd list, t_ldcd_cell *cur, int rev)
{
	if (rev)
		*cur = ((*cur)->prev) ? (*cur)->prev : list->tail;
	else
		*cur = ((*cur)->next) ? (*cur)->next : list->head;
}

void	ft_getneighbors(t_ldcd list, t_ldcd_cell *cur, int rev)
{
	int		ycur;

	ycur = S_ELEM_CONT((*cur), y);
	ft_getnextelem(list, cur, rev);
	while (ycur != S_ELEM_CONT((*cur), y))
		ft_getnextelem(list, cur, rev);
}

