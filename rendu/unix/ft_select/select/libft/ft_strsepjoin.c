/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsepjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 20:18:05 by tseguier          #+#    #+#             */
/*   Updated: 2013/12/28 20:18:40 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsepjoin(char **dir, char *name, char *sep)
{
	char	*newpath;

	if (!dir || !name || !*dir)
		return (-1);
	newpath = ft_strjoin(*dir, sep);
	if (!newpath)
		return (-2);
	ft_strdel(dir);
	*dir = newpath;
	newpath = ft_strjoin(*dir, name);
	ft_strdel(dir);
	*dir = newpath;
	return ((*dir) ? 0 : -3);
}

