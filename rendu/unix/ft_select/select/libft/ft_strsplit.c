/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 13:58:54 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/30 21:13:44 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static unsigned int		ft_countwords(char const *s, char c)
{
	int			i;

	i = 0;
	while (s[i] == c)
		++i;
	if (s[i] == '\0')
		return (0);
	while (s[i] != c && s[i] != '\0')
		++i;
	return (1 + ft_countwords(s + i, c));
}

static void				ft_extractwords(char ***wordtab_p, char const *s,
										size_t nbwords, char c)
{
	unsigned int	i;
	unsigned int	tabi;
	size_t			wordlen;

	i = 0;
	tabi = 0;
	while (tabi < nbwords)
	{
		wordlen = 0;
		while (s[i] == c)
			++i;
		while (s[(size_t)i + wordlen] != c && s[(size_t)i + wordlen] != '\0')
			++wordlen;
		(*wordtab_p)[tabi] = ft_strsub(s, i, wordlen);
		++tabi;
		if (!(*wordtab_p)[tabi - 1])
		{
			while (tabi-- > 0)
				ft_strdel(*wordtab_p + tabi);
			free (*wordtab_p);
			*wordtab_p = NULL;
			return ;
		}
		i += (unsigned int)wordlen;
	}
}

char					**ft_strsplit(char const *s, char c)
{
	size_t			nbwords;
	char			**wordtab;

	if (!s)
		return (NULL);
	nbwords = ft_countwords(s, c);
	wordtab = (char **)malloc(sizeof(char *) * (nbwords + 1));
	if (!wordtab)
		return (NULL);
	wordtab[nbwords] = NULL;
	if (nbwords > 0)
		ft_extractwords(&wordtab, s, nbwords, c);
	return (wordtab);
}


