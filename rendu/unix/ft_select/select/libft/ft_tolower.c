/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 07:06:32 by tseguier          #+#    #+#             */
/*   Updated: 2013/11/27 13:46:22 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	return ((c > 64 && c < 91) ? c + 32 : c);
}

