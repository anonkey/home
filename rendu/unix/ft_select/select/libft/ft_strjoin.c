/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:17:22 by tseguier          #+#    #+#             */
/*   Updated: 2013/12/28 20:30:52 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!newstr)
		return (NULL);
	ft_strcpy(newstr, s1);
	return (ft_strcat(newstr, s2));
}

