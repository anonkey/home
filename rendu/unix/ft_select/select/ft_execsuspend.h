/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execsuspend.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 00:05:09 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/12 00:15:10 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECSUSPEND_H
# define FT_EXECSUSPEND_H
# include "libft.h"
# include "ft_term.h"

void		ft_termclean(t_term term);

void		ft_termrest(t_term term, t_ldcd lst);

#endif /* !FT_EXECSUSPEND_H */
