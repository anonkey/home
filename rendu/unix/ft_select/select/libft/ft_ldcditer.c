/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcditer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 04:08:00 by tseguier          #+#    #+#             */
/*   Updated: 2013/12/04 06:23:59 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ldcd_cell.h"

void	ft_ldcditer(t_ldcd ldcd, void (*f)(void *elem, size_t elemsize))
{
	t_ldcd_cell		iter;

	if (!ldcd || !f)
		return ;
	iter = ldcd->head;
	while (iter)
	{
		(*f)(iter->content, iter->content_size);
		iter = iter->next;
	}
}

