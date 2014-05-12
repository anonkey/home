/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 08:46:01 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/30 16:42:28 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int		ft_str_dismatch(const char *str1, const char *str2)
{
	size_t		i;

	i = 0;
	while (str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (1);
		else
			++i;
	}
	return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	size_t			s2len;

	if (!s1 || !s2)
		return (NULL);
	s2len = ft_strlen(s2);
	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && s2len + i <= n)
	{
		if (ft_str_dismatch(&s1[i], s2) == 0)
			return ((char *)&s1[i]);
		++i;
	}
	return (NULL);
}

