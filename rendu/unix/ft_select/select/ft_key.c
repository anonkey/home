/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 00:11:46 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/11 23:20:00 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key.h"

ssize_t	ft_getkey(t_key key)
{
	ssize_t		i;

	i = read(0, key, MAXKEYLEN);
	while (i < MAXKEYLEN && i > 0)
	{
		key[i] = '\0';
		++i;
	}
	return (i);
}

char	ft_keycmp(t_key key1, t_key key2)
{
	int		i;

	i = 0;
	while (i < MAXKEYLEN - 1)
	{
		if (key1[i] != key2[i])
			return (key1[i] - key2[i]);
		++i;
	}
	return (key1[i] - key2[i]);
}


