/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 08:29:51 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/10 04:29:33 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# define PROG_NAME "ft_select"
# define FATSYSERR 0
# define SYSERR 1
# define FATERR 2
# define PROGERR 3

void	ft_perror(const char *prog, const char *s, int errnum, int fatal);

#endif /* !FT_ERROR_H */

