/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 22:11:55 by tseguier          #+#    #+#             */
/*   Updated: 2014/05/02 15:53:03 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <term.h>
#include "libft.h"
#include "ft_term.h"

int		ft_putintchar(int c)
{
	int		fd;
	char	chr;

	fd = open("/dev/tty", O_WRONLY);
	chr = (char)c;
	if (0 == write(fd, &chr, 1))
		return (0);
	close(fd);
	return (1);
}

static void	ft_termcmd_init(t_sysstr *cmdlist)
{
	cmdlist->clstr = tgetstr("cl", NULL);
	cmdlist->ascrstr = tgetstr("ti", NULL);
	cmdlist->nscrstr = tgetstr("te", NULL);
	cmdlist->curvstr = tgetstr("ve", NULL);
	cmdlist->curistr = tgetstr("vi", NULL);
	cmdlist->ulsstr = tgetstr("us", NULL);
	cmdlist->ulestr = tgetstr("ue", NULL);
	cmdlist->rvsstr = tgetstr("so", NULL);
	cmdlist->rvestr = tgetstr("se", NULL);
}

t_term		ft_termnew(void)
{
	t_term			newterm;
	struct winsize	wins;

	newterm = (t_term)malloc(sizeof(struct s_term));
	if (!newterm)
		return (NULL);
	newterm->name = ft_strdup(getenv("TERM"));
	if (!newterm->name)
		return (NULL);
	if (1 != tgetent(NULL, newterm->name))
		return (NULL);
	if (-1 == tcgetattr(0, &(newterm->term_p)) ||
		-1 == tcgetattr(0, &(newterm->term_pbak)))
		return (NULL);
	ft_termcmd_init(&(newterm->controls));
	if (!newterm->controls.clstr)
		return (NULL);
	newterm->ttys = open("/dev/tty", O_WRONLY);
	if (newterm->ttys == -1)
		return (NULL);
	ioctl(0, TIOCGWINSZ, &wins);
	newterm->li = wins.ws_row;
	newterm->co = wins.ws_col;
	return (newterm);
}

void		ft_termdel(t_term *term)
{
	ft_strdel(&((*term)->name));
	ft_memdel((void **)term);
}

void		ft_termclear(t_term term)
{
	tputs(term->controls.clstr, 1, &ft_putintchar);
}


