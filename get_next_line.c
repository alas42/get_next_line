/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:23:18 by avogt             #+#    #+#             */
/*   Updated: 2018/11/17 17:44:56 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "Libft/libft.h"
#include <stdio.h>

static int	ft_loop(char **line, int fd, int *ret,
		size_t *size)
{
	char				*o;
	static unsigned int t;

	t = 0;
	o = NULL;
	while ((*line)[t] != '\n' && (*line)[t] != '\0' && t < BUFF_SIZE)
		t++;
	if (((*line)[t] == '\n' || (*line)[t] == EOF
				|| (*line)[t] == '\0') && t < BUFF_SIZE)
	{
		if ((*line)[t] == '\n')
			return (1);
		else
			return (0);
	}
	if (t == BUFF_SIZE)
	{
		*size += BUFF_SIZE;
		if (!(o = (char *)malloc(sizeof(char) * (*size))))
			return (-1);
		ft_memcpy(o, *line, *size - BUFF_SIZE);
		*line = o;
		ft_putstr("\nin ft_loop = ");
		ft_putstr(*line);
		free(o);
		*ret = read(fd, *line, BUFF_SIZE);
		if (*ret == -1)
			return (*ret);
		(*line)[*size] = '\0';
	}
	return (2);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	int				a;
	size_t			size;

	a = 2;
	ret = 1;
	size = BUFF_SIZE + 1;
	if (!(*line = (char *)malloc(sizeof(char) * size)))
	{
		free(*line);
		return (-1);
	}
	ret = read(fd, *line, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	(*line)[BUFF_SIZE] = '\0';
	while (a == 2)
	{
		a = ft_loop(line, fd, &ret, &size);
		ft_putstr("\nline = ");
		ft_putstr(*line);
	}
	return (a);
}
