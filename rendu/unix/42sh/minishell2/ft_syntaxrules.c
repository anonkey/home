/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntaxrules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 04:00:20 by tseguier          #+#    #+#             */
/*   Updated: 2014/02/06 23:14:52 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_syntax.h"

int			ft_syntax_checksep(t_lexer lex, int sepind)
{
	int		next_sep;
	int		search;

	if (!lex || sepind < 0 || sepind >= NB_SEPSTR)
		return (-1);
	search = lex->syntax.sepdict[sepind].len;
	while (lex->strin[lex->strstart + search] == T_SEP_CHAR)
		++search;
	next_sep = ft_lex_getsep(lex, search);
	if (next_sep == -1)
		return (0);
	ft_putstr_fd("Parse error near : ", 2);
	ft_putstr_fd(lex->syntax.sepdict[sepind].label, 2);
	ft_putendl_fd(lex->syntax.sepdict[next_sep].label, 2);
	return (-2);
}

