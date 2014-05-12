/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sellist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 20:40:39 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/12 08:21:05 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELLIST_H
# define FT_SELLIST_H
# include "libft.h"
# include "ft_term.h"
# include "ft_key.h"

/*
** S_ELEM_CONT : access to field 'field' in t_selelem content
** of a t_ldcd_cell
*/
# define S_ELEM_CONT(cell, field) ((t_selelem)(cell->content))->field

/*
** ft_processkey error codes
*/
# define PKARGERR -1
# define PKMEMERR -2
# define PKLSTERR -3
/*
** Arrow keys codes
*/
# define UPKEYCODE 65
# define DOWNKEYCODE 66
# define RIGHTKEYCODE 67
# define LEFTKEYCODE 68

typedef struct	s_selectelem
{
	char	*str;
	int		style;
	int		x;
	int		y;
}				*t_selelem;

t_selelem	ft_selelem_new(void);

void		ft_selelem_del(t_selelem *elem_p, int delstr);

void		ft_putlist(t_ldcd sellist, t_term term);

int			ft_selmove(t_ldcd sellist, t_ldcd_cell *curr, int key);

int			ft_selchoose(t_ldcd sellist, t_ldcd_cell *cur);

int			ft_processkey(t_key key, t_term term, t_ldcd lst, t_ldcd_cell *cur);

void		ft_getnextelem(t_ldcd list, t_ldcd_cell *cur, int rev);

void		ft_getneighbors(t_ldcd list, t_ldcd_cell *cur, int rev);

#endif /* !FT_SELLIST_H */

