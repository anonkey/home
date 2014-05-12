/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 22:19:35 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/12 07:01:26 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H
# include <termios.h>

typedef struct		s_sysstr
{
	char			*clstr;
	char			*ascrstr;
	char			*nscrstr;
	char			*curistr;
	char			*curvstr;
	char			*ulsstr;
	char			*ulestr;
	char			*rvsstr;
	char			*rvestr;
}					t_sysstr;

typedef struct		s_term
{
	char			*name;
	t_sysstr		controls;
	int				ttys;
	int				li;
	int				co;
	struct termios	term_p;
	struct termios	term_pbak;
}					*t_term;

int			ft_putintchar(int c);

t_term		ft_termnew(void);

void		ft_termdel(t_term *term);

void		ft_termclear(t_term term);

void		ft_term_curon(t_term term);

void		ft_term_curoff(t_term term);

void		ft_term_ulon(t_term term);

void		ft_term_uloff(t_term term);

void		ft_term_rvon(t_term term);

void		ft_term_rvoff(t_term term);

void		ft_term_ascron(t_term term);

void		ft_term_ascroff(t_term term);

int			ft_termnoncanon(t_term term);

int			ft_termcanon(t_term term);

int			ft_termsigon(t_term term);

#endif /* !FT_TERM_H */

