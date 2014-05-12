/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sighandler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 00:52:04 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/12 09:01:45 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGHANDLER_H
# define FT_SIGHANDLER_H
# include "ft_term.h"

void	ft_sigint(int sig);

void	ft_sigquit(int sig);

void	ft_sigtstp(int sig);

void	ft_sigwinch(int sig);

void	ft_sigcont(int sig);

#endif /* !FT_SIGHANDLER_H */
