/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:18:05 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/30 16:46:41 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	while (s[i] != '\0')
		++i;
	i--;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		--i;
	i = (i < 0) ? 0 : i;
	return (ft_strsub(s, 0, i + 1));
}

