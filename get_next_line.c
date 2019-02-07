/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:12:40 by avogt             #+#    #+#             */
/*   Updated: 2019/02/07 17:29:56 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_lenl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static char		*ft_reset_str(char **s1, char *s2, int i, int j)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(*s1, s2);
	if (i == 1 && *s1 != NULL)
		ft_strdel(s1);
	if (j == 1)
		ft_strdel(&s2);
	return (tmp);
}

static int		ft_read(int fd, char **next)
{
	int		ret;
	char	tmp[BUFF_SIZE + 1];

	ret = 0;
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		*next = ft_reset_str(next, tmp, 1, 0);
		if (ft_strchr(*next, '\n') != NULL)
			return (1);
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*next = NULL;
	int			result;

	if (fd < 0 || line == NULL)
		return (-1);
	next = ft_strdup("");
	result = ft_read(fd, &next);
	if (result == -1)
		return (-1);
	if (next)
	{
		if (ft_strchr(next, '\n') != NULL)
		{
			*line = ft_strsub(next, 0, ft_lenl(next));
			next = ft_strsub(next, ft_lenl(next) + 1, ft_strlen(next));
		}
		else if (ft_strlen(next) == 0)
			(*line) = ft_strdup("");
		return (1);
	}
	else
	{
		(*line) = ft_strdup("");
		return (0);
	}
}