/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:01:11 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/27 17:10:47 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*memarea;

	memarea = malloc(size);
	if (!memarea)
		return (NULL);
	while (size > 0)
		((char *)memarea)[--size] = '\0';
	return (memarea);
}

