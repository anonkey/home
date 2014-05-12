/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 22:59:08 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/11 06:36:34 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_KEY_H
# define FT_KEY_H
# include <unistd.h>
# include <sys/types.h>
# define MAXKEYLEN 8

typedef char	t_key[MAXKEYLEN];

ssize_t	ft_getkey(t_key key);

char	ft_keycmp(t_key key1, t_key key2);

#endif /* !FT_KEY_H */
