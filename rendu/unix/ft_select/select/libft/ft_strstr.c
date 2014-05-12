/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/17 04:50:59 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/27 17:27:01 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int		ft_str_dismatch(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (str2[i] != '\0' )
	{
		if (str1[i] != str2[i])
			return (1);
		else
			++i;
	}
	return (0);
}

char	*ft_strstr(const char *s1, const char *s2)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0' )
	{
		if (ft_str_dismatch(s1, s2) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

