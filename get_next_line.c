/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:23:18 by avogt             #+#    #+#             */
/*   Updated: 2018/11/19 17:03:53 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "Libft/libft.h"
#include <stdio.h>


static int	ft_loop(char **line, int fd, size_t *size)
{
	static unsigned int t;
	char				*tmp;
	int					ret;
	int					i;

	i = 0;
	t = 0;
	while ((*line)[t] != '\n' && (*line)[t] != '\0' && t < BUFF_SIZE)
		t++;
	if (((*line)[t] == '\n' || (*line)[t] == EOF
				|| (*line)[t] == '\0') && t < BUFF_SIZE)
	{
		(*line)[t] = '\0';
		if ((*line)[t] == '\n')
			return (1);
		else
			return (0);
	}
	else if (t == BUFF_SIZE)
	{
		tmp = *line;
		free(*line);
		*size += BUFF_SIZE;
		if (!(*line = (char *)malloc(sizeof(char) * (*size))))
			return (-1);
		ft_putnbr(*size);
		ft_putchar('\n');
		*line = tmp;
		(*line)[*size - 1] = '\0';
		ft_putstr("\n1. LINE\n");
		ft_putstr(*line);
		ft_putchar('\n');
		++line;
		ret = read(fd, *line, BUFF_SIZE);
	}
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	size_t			size;

	ret = 1;
	size = BUFF_SIZE + 1;
	if (!(*line = (char *)malloc(sizeof(char) * size)))
		return (-1);
	if ((ret = read(fd, *line, BUFF_SIZE)) == -1)
		return (-1);
	(*line)[BUFF_SIZE] = '\0';
	return (ft_loop(line, fd, &size));
}
