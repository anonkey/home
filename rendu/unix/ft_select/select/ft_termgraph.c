/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termgraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 03:11:38 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/12 07:02:57 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termcap.h>
#include "ft_term.h"

void			ft_term_ulon(t_term term)
{
	tputs(term->controls.ulsstr, 1, &ft_putintchar);
}

void			ft_term_uloff(t_term term)
{
	tputs(term->controls.ulestr, 1, &ft_putintchar);
}

void			ft_term_rvon(t_term term)
{
	tputs(term->controls.rvsstr, 1, &ft_putintchar);
}

void			ft_term_rvoff(t_term term)
{
	tputs(term->controls.rvestr, 1, &ft_putintchar);
}

