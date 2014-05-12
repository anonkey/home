/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:08:02 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/30 16:29:40 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nbstr;

	if (fd < 0)
		return ;
	nbstr = ft_itoa(n);
	ft_putstr_fd(nbstr, fd);
	ft_strdel(&nbstr);
}

