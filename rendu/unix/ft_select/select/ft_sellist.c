/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sellist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 20:20:40 by tseguier          #+#    #+#             */
/*   Updated: 2014/05/02 15:58:45 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include <termcap.h>
#include "ft_sellist.h"
#include "ft_term.h"

size_t		ft_getcolsize(t_ldcd_cell cur)
{
	size_t		colsize;
	size_t		temp;

	colsize = 0;
	while (cur)
	{
		if ((temp = ft_strlen(S_ELEM_CONT(cur, str))) > colsize)
			colsize = temp;
		cur = cur->next;
	}
	return (colsize + 3);
}

size_t		ft_refreshpos(t_ldcd sellist, t_term term)
{
	t_ldcd_cell	iter;
	size_t		colsize;
	size_t		linesize;
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	iter = sellist->head;
	colsize = ft_getcolsize(iter);
	if (0 == (linesize = (term->co / colsize) - 1))
		return (0);
	linesize = ft_ldcdsize(sellist) / linesize;
	while (iter)
	{
		S_ELEM_CONT(iter, x) = x;
		S_ELEM_CONT(iter, y) = y;
		iter = iter->next;
		if (y + 1 >= linesize)
		{
			y = 0;
			x += colsize;
		}
		else
			++y;
	}
	return ((linesize > (size_t)term->li) ? 0 : colsize);
}


void	ft_putlist(t_ldcd sellist, t_term term)
{
	t_ldcd_cell	iter;
	size_t		colsize;
	char		*mv;

	colsize = ft_refreshpos(sellist, term);
	if (colsize == 0)
		ft_putstr_fd("Windows is too small, please enlarge.", term->ttys);
	iter = sellist->head;
	while (iter && colsize != 0)
	{
		mv = tgetstr("cm", NULL);
		mv = tgoto(mv, S_ELEM_CONT(iter, x), S_ELEM_CONT(iter, y));
		tputs(mv, 1, &ft_putintchar);
		if (S_ELEM_CONT(iter, style) & 1)
			ft_term_ulon(term);
		if (S_ELEM_CONT(iter, style) & 2)
			ft_term_rvon(term);
		ft_putstr_fd(S_ELEM_CONT(iter, str), term->ttys);
		if (S_ELEM_CONT(iter, style) & 1)
			ft_term_uloff(term);
		if (S_ELEM_CONT(iter, style) & 2)
			ft_term_rvoff(term);
		iter = iter->next;
	}
}

int		ft_selmove(t_ldcd sellist, t_ldcd_cell *cur, int key)
{
	if (!sellist || !cur)
		return (-1);
	S_ELEM_CONT((*cur), style) -= 1;
	if (key == UPKEYCODE)
		*cur = ((*cur)->prev) ? (*cur)->prev : sellist->tail;
	if (key == DOWNKEYCODE)
		*cur = ((*cur)->next) ? (*cur)->next : sellist->head;
	if (key == RIGHTKEYCODE)
		ft_getneighbors(sellist, cur, 0);
	if (key == LEFTKEYCODE)
		ft_getneighbors(sellist, cur, 1);
	if (cur)
		S_ELEM_CONT((*cur), style) += 1;
	return (1);
}

int		ft_selchoose(t_ldcd sellist, t_ldcd_cell *cur)
{
	if (!sellist || !cur)
		return (-1);
	if (((t_selelem)((*cur)->content))->style & 2)
		((t_selelem)((*cur)->content))->style -= 2;
	else
		((t_selelem)((*cur)->content))->style += 2;
	ft_selmove(sellist, cur, DOWNKEYCODE);
	return (1);
}

