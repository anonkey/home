/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:01:53 by tseguier          #+#    #+#             */
/*   Updated: 2014/05/02 15:56:29 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <term.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include "libft.h"
#include "ft_term.h"
#include "ft_key.h"
#include "ft_sighandler.h"
#include "ft_execsuspend.h"
#include "ft_error.h"
#include "ft_sellist.h"


t_ldcd		ft_parseargs(int argc, char **argv)
{
	t_ldcd		elst;
	t_selelem	elem;
	int			i;

	i = 1;
	if (argc < 2)
		ft_perror(PROG_NAME, "ft_select word1 [word2 ...  wordN]", 5, FATERR);
	elst = ft_ldcdnew();
	elem = ft_selelem_new();
	if (!elem)
	{
		ft_ldcddel(&elst, &ft_memdel);
		return (NULL);
	}
	while (i < argc)
	{
		elem->str = ft_strdup(argv[i]);
		elem->style = (i == 1);
		if (!elem
			|| -1 == ft_ldcdpush_back(elst, elem, sizeof(struct s_selectelem)))
			return (NULL);
		++i;
	}
	ft_selelem_del(&elem, 0);
	return (elst);
}

int		ft_terminit(t_term term)
{
	signal(SIGINT, &ft_sigint);
	signal(SIGWINCH, &ft_sigwinch);
	signal(SIGTSTP, &ft_sigtstp);
	signal(SIGCONT, &ft_sigcont);
	signal(SIGQUIT, &ft_sigquit);
	ft_termnoncanon(term);
	ft_termsigon(term);
	ft_term_curoff(term);
	ft_term_ascron(term);
	ft_termclear(term);
	return (0);
}
void	ft_exit(t_term term, t_ldcd list)
{
	t_selelem	temp;

	ft_termclean(term);
	while (ft_ldcdsize(list))
	{
		temp = (t_selelem)ft_ldcdpop_front(list);
		if (temp->style & 2)
		{
			ft_putstr(temp->str);
			ft_putchar(' ');
		}
		ft_selelem_del(&temp, 1);
	}
	ft_ldcddel(&list, &ft_memdel);
	ft_termdel(&term);
}

void	ft_keyloop(t_term term, t_ldcd list)
{
	int			status;
	t_key		key;
	t_ldcd_cell	iter;

	status = 1;
	iter = list->head;
	while (status > 0)
	{
		status = ft_getkey(key);
		if (status != -1)
			status = ft_processkey(key, term, list, &iter);
		if (status == 1)
		{
			ft_termclear(term);
			ft_putlist(list, term);
		}
	}
}

int		main(int argc, char **argv)
{
	t_term		term;
	t_ldcd		list;

	if (!getenv("TERM"))
		ft_perror("ft_select", NULL, 12, 2);
	list = ft_parseargs(argc, argv);
	if (!list)
		return (-2);
	term = ft_termnew();
	if (term == NULL)
		return (-3);
	ft_terminit(term);
	ft_putlist(list, term);
	ft_keyloop(term, list);
	ft_exit(term, list);
	return (0);
}

