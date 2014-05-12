/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:55:55 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/30 21:14:05 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*maplst;
	t_list		*maplst_iter;
	t_list		*mapelem;

	if (!f || !lst)
		return (NULL);
	mapelem = (*f)(lst);
	maplst = ft_lstnew(mapelem->content, mapelem->content_size);
	if (!maplst)
		return (NULL);
	maplst_iter = maplst;
	lst = lst->next;
	while (lst)
	{
		mapelem = (*f)(lst);
		maplst_iter->next = ft_lstnew(mapelem->content, mapelem->content_size);
		if (!maplst_iter->next)
			return (NULL);
		maplst_iter = maplst_iter->next;
		lst = lst->next;
	}
	return (maplst);
}

