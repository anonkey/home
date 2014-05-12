/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 20:29:57 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/12 02:35:16 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_sellist.h"

t_selelem	ft_selelem_new(void)
{
	t_selelem	newelem;

	newelem = (t_selelem)malloc(sizeof(struct s_selectelem));
	if (!newelem)
		return (NULL);
	newelem->str = NULL;
	newelem->style = 0;
	return (newelem);
}

void		ft_selelem_del(t_selelem *elem_p, int delstr)
{
	if (delstr != 0)
		ft_strdel(&((*elem_p)->str));
	ft_memdel((void **)elem_p);
}

