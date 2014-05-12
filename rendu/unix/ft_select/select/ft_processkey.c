/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processkey.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 01:10:31 by tseguier          #+#    #+#             */
/*   Updated: 2014/05/02 15:58:25 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ft_key.h"
#include "ft_term.h"
#include "ft_execsuspend.h"
#include "ft_error.h"
#include "ft_sighandler.h"
#include "ft_sellist.h"
#include "libft.h"

static int		ft_sigh_treat(t_term term, char c, int kill)
{
	char		buff[2] = "\0";

	ft_termclean(term);
	buff[0] = c;
	ioctl(0, TIOCSTI, buff);
	if (kill)
	{
		ioctl(0, TIOCSTI, "\n");
		ft_termdel(&term);
		exit (1);
	}
	return (2);
}

static int			ft_deletepress(t_ldcd sellist, t_ldcd_cell *cur)
{
	t_selelem	elem;
	t_ldcd_cell	temp;

	if (!sellist || !cur)
		return (-1);
	temp = ((*cur)->next) ? (*cur)->next : (*cur)->prev;
	if (temp && !temp->content)
		return (-2);
	elem = (t_selelem)ft_ldcdpop(sellist, *cur);
	if (!elem)
		return (-3);
	ft_selelem_del(&elem, 1);
	*cur = temp;
	if (*cur)
		((t_selelem)(temp->content))->style += 1;
	return ((*cur) ? 1 : 0);
}

int		ft_classickeypress(t_ldcd lst, t_key key, t_ldcd_cell *cur)
{
	if (!key || !lst || !cur)
		return (-1);
	if (key[0] == 32)
		return (ft_selchoose(lst, cur));
	else if (key[0] == 127)
		return (ft_deletepress(lst, cur));
	else if (key[0] == 10 || key[0] == 27)
		return (0);
	return (2);
}

int		ft_specialkeypress(t_ldcd lst, t_key key, t_ldcd_cell *cur)
{
	if (!key || !lst || !cur)
		return (-1);
	if (key[2] >= 65 && key[2] <= 68 && key[3] == 0)
		return (ft_selmove(lst, cur, (int)key[2]));
	if (key[2] == 51 && key[3] == 126)
		return (ft_deletepress(lst, cur));
	return (2);
}

int			ft_processkey(t_key key, t_term term, t_ldcd lst, t_ldcd_cell *cur)
{
	int				status;
	struct winsize	wins;

	status = 2;
	if (key[0] == '\254' && isatty(1))
	{
		signal(SIGTSTP, SIG_DFL);
		ft_sigh_treat(term, term->term_p.c_cc[VSUSP], 0);
	}
	if (key[0] == '\254' && isatty(1))
		ft_termrest(term, lst);
	else if (key[0] == '\253')
		return (ft_sigh_treat(term, term->term_p.c_cc[VKILL], 1));
	else if (key[0] == '\252')
		return (ft_sigh_treat(term, term->term_p.c_cc[VQUIT], 1));
	else if (key[0] == '\251')
	{
		ioctl(0, TIOCGWINSZ, &wins);
		term->li = wins.ws_row;
		term->co = wins.ws_col;
		ft_termclear(term);
		ft_putlist(lst, term);
		return (1);
	}
	else if (key[1] == 0 && key[2] == 0 && key[3] == 0)
		return (ft_classickeypress(lst, key, cur));
	else if (key[0] == 27 && key[1] == 91)
		return (ft_specialkeypress(lst, key, cur));
	return (2);
}

