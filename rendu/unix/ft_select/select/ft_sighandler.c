/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sighandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 00:40:12 by tseguier          #+#    #+#             */
/*   Updated: 2014/05/02 15:58:06 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "ft_term.h"
#include "ft_execsuspend.h"
#include "ft_error.h"

void	ft_sigint(int sig)
{
	signal(sig, SIG_DFL);
	ioctl(0, TIOCSTI, "\253");
}

void	ft_sigquit(int sig)
{
	signal(sig, SIG_DFL);
	ioctl(0, TIOCSTI, "\252");
}

void	ft_sigtstp(int sig)
{
	ioctl(0, TIOCSTI, "\254");
	if (sig)
		signal(sig, SIG_IGN);
}

void	ft_sigwinch(int sig)
{
	if (sig)
		ioctl(0, TIOCSTI, "\251");
}

void	ft_sigcont(int sig)
{
	if (sig)
		signal(SIGTSTP, &ft_sigtstp);
}


