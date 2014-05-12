/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:06:21 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/30 16:30:40 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t		i;

	if (!s || fd < 0)
		return ;
	i = ft_strlen(s);
	if (i > 0 && fd > 0)
		write(fd, s, i);
}

