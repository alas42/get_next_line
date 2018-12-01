/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:12:24 by avogt             #+#    #+#             */
/*   Updated: 2018/12/01 18:55:48 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int			ft_lenline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static int	ft_read(int fd, char **buff)
{
	int		ret;
	char	tmp[BUFF_SIZE + 1];

	ret = 0;
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[BUFF_SIZE] = '\0';
		*buff = ft_strjoin(*buff, tmp);
		dprintf(1, "buff : %s\n", *buff);
		if (ft_strchr(*buff, '\n') != NULL)
			return (1);
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *next = NULL;
	char		*buff;
	int			result;

	buff = NULL;
	if (next)
	{
		*line = ft_strsub(next, 0, ft_lenline(next));
		if (ft_strchr(next, '\n') != NULL)
		{
			next = ft_strsub(next, ft_lenline(next) + 1, ft_strlen(next));
			dprintf(1, "lenline de next = %d\n", ft_lenline(next));
			dprintf(1, "next %s\n", next);
			return (1);
		}
		*line = ft_strdup(next);
		ft_strdel(&next);
	}
	result = ft_read(fd, &buff);
	if (result == 1)
	{
		next = ft_strsub(buff, ft_lenline(buff) + 1, ft_strlen(buff));
		dprintf(1, "lenline de buff : %d  + len de buff : %zu\n", ft_lenline(buff), ft_strlen(buff));
		*line = ft_strjoin(*line, ft_strsub(buff, 0, ft_lenline(buff)));
	}
	else if (result == 0)
		*line = ft_strjoin(*line, buff);
	ft_strdel(&buff);
	return (result);
}
