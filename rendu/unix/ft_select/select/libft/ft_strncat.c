/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:22:12 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/27 17:21:51 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return (s1);
	while (s1[i] != '\0')
		++i;
	while ((int)n - j > 0)
	{
		s1[i + j] = s2[j];
		++j;
	}
	s1[i + j] = '\0';
	return (s1);
}

