/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabrealloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 05:51:57 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/08 22:44:13 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strtabrealloc(char ***strtab, int addsize)
{
	char	**newtab;

	newtab = ft_strtabcpy(*strtab, addsize);
	if (!newtab)
		return (-1);
	ft_strtabdel(strtab);
	*strtab = newtab;
	return (0);
}

