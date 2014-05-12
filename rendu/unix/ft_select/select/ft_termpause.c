/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termpause.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 23:43:31 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/11 23:46:45 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_termclean(t_term term)
{
	ft_termclear(term);
	ft_term_ascroff(term);
	ft_term_curon(term);
	ft_termcanon(term);
	tcsetattr(0, TCSANOW, &(term->term_pbak));
}

void		ft_termrest(t_term term, t_ldcd lst)
{
	ft_term_curoff(term);
	ft_termnoncanon(term);
	tcsetattr(0, TCSANOW, &(term->term_p));
	tputs(term->controls.ascrstr, 1, &ft_putintchar);
	ft_termclear(term);
	ft_putlist(lst, term);
}

