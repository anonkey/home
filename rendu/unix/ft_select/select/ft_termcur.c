/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 21:22:28 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/12 08:50:22 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include "ft_term.h"

void	ft_term_curon(t_term term)
{
	tputs(term->controls.curvstr, 1, &ft_putintchar);
}

void	ft_term_curoff(t_term term)
{
	tputs(term->controls.curistr, 1, &ft_putintchar);
}

