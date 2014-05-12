/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termopt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 22:22:24 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/12 07:03:41 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_term.h"

int			ft_termnoncanon(t_term term)
{
	term->term_p.c_lflag &= ~ICANON;
	term->term_p.c_lflag &= ~ECHO;
	if (-1 == tcsetattr(0, TCSANOW, &(term->term_p)))
		return (-1);
	return (0);
}

int			ft_termcanon(t_term term)
{
	term->term_p.c_lflag |= ECHO;
	term->term_p.c_lflag |= ICANON;
	if(-1 == tcsetattr(0, TCSANOW, &(term->term_p)))
		return (-1);
	return (0);
}

int			ft_termsigon(t_term term)
{
	term->term_p.c_lflag |= ISIG;
	if(-1 == tcsetattr(0, TCSANOW, &(term->term_p)))
		return (-1);
	return (0);
}

void			ft_term_ascron(t_term term)
{
	tputs(term->controls.ascrstr, 1, &ft_putintchar);
}

void			ft_term_ascroff(t_term term)
{
	tputs(term->controls.nscrstr, 1, &ft_putintchar);
}

