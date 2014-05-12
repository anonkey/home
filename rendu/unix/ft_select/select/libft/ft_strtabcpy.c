/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:21:44 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/08 22:44:49 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_strtabcpy(char **strtab, int addsize)
{
	int		len;
	char	**newtab;

	len = 0;
	if (!strtab)
		return (NULL);
	while (strtab[len])
		len++;
	newtab = (char **)malloc(sizeof(char *) * (len + addsize +  1));
	if (!newtab)
		return (NULL);
	--len;
	while (len >= 0)
	{
		newtab[len] = ft_strdup(strtab[len]);
		if(!newtab[len])
		{
			ft_strtabdel(&newtab);
			return (NULL);
		}
		--len;
	}
	return (newtab);
}

