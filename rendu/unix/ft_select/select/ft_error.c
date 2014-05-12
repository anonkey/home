/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 05:34:37 by tseguier          #+#    #+#             */
/*   Updated: 2014/05/02 15:57:07 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_error.h"

#define TAB_ERR_SIZE 13
#define ERR_MSG_SIZE_MAX 64

extern const char *		const		sys_errlist[];

static const char		ft_errortab[TAB_ERR_SIZE][ERR_MSG_SIZE_MAX] =
{
	"Unknown error",
	"Not enough memory",
	"No such file or directory",
	"Command not found",
	"Can't fork",
	"Bad arguments, Usage",
	"Permission denied",
	"Can't execute command",
	"Can't read stdin",
	"File not found",
	"Signal received",
	"Missing env var",
	"Terminal not fully fonctionnal"
};


void	ft_perror(const char *prog, const char *s, int errnum, int type)
{
	char const		*error;

	if (errnum >= TAB_ERR_SIZE)
		errnum = 0;
	if (prog)
	{
		ft_putstr_fd(prog, 2);
		ft_putstr_fd(" : ", 2);
	}
	error = (type > 1) ? ft_errortab[errnum] : (char *)sys_errlist[errnum];
	ft_putstr_fd(error, 2);
	if (s)
	{
		ft_putstr_fd(" : ", 2);
		ft_putstr_fd(s, 2);
	}
	ft_putstr_fd("\n", 2);
	if (type % 2 == 0)
		exit(1);
}


