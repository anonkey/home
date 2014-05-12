/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 00:19:55 by tseguier          #+#    #+#             */
/*   Updated: 2013/12/29 11:06:04 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_ldcdline_length(t_ldcd list)
{
	t_ldcd_cell		iter;
	size_t			length;
	char			*separ;

	length = 1;
	iter = list->head;
	while (iter && !(separ = ft_strchr((char *)list->head->content, 10)))
	{
		length += iter->content_size - 1;
		iter = iter->next;
	}
	return (length);
}

int		ft_ldcdextract_line(t_ldcd list,char **line)
{
	char		*separ;
	size_t		linelength;
	size_t		endline;

	linelength = ft_ldcdline_length(list);
	if (!list || !line)
		return (-1);
	*line = ft_strnew(linelength);
	while (list->head && !(separ = ft_strchr((char *)list->head->content, 10)))
	{
		ft_strcat(*line, (char *)list->head->content);
		ft_ldcddel_head(list);
	}
	if (!list->head)
		return (1);
	endline = (size_t)(separ - (char *)list->head->content);
	ft_strncat(*line, (char *)list->head->content, endline);
	separ = ft_strdup(separ + 1);
	ft_ldcdpush_back(list, separ, ft_strlen(separ) + 1);
	ft_ldcddel_head(list);
	return (1);
}

int		ft_fillbuffer(t_ldcd bufflist, int fd, char **line, int readl)
{
	ssize_t				readstatus;
	char				*buffer;

	readstatus = BUFF_SIZE;
	buffer = ft_strnew(BUFF_SIZE);
	if (!buffer)
		return (-1);
	*buffer = '\0';
	while (readl == 0 && !ft_strchr(buffer, '\n') && readstatus == BUFF_SIZE)
	{
		readstatus = read(fd, buffer, BUFF_SIZE);
		if (readstatus == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[readstatus] = '\0';
		ft_ldcdpush_back(bufflist, buffer, BUFF_SIZE + 1);
	}
	if (readl == 0 && (-1 == ft_ldcdextract_line(bufflist, line) || !*line))
	{
		free(buffer);
		return (-1);
	}
	return ((readstatus == BUFF_SIZE || ft_ldcdsize(bufflist) > 0) ? 1 : 0);
}

int		get_next_line(int const fd, char ** line)
{
	static t_ldcd		bufflist = NULL;
	int					readl;

	readl = 0;
	if (!bufflist)
		bufflist = ft_ldcdnew();
	if (!bufflist || !line)
		return (-1);
	if (ft_ldcdsize(bufflist) > 0)
	{
		if (ft_strchr((char *)bufflist->head->content, '\n'))
		{
			readl = 1;
			ft_ldcdextract_line(bufflist, line);
			return (1);
		}
	}
	return(ft_fillbuffer(bufflist, fd, line, readl));
}


