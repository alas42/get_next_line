/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:23:18 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 18:43:27 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_putchar2(c)
{
	write(1, &c, 1);
}

static void	ft_putstr_len(char *s, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		ft_putchar2(s[i]);
		i++;
	}
}

int			get_next_line(const int fd, char **line)
{
	int		ret;
	int		linend;
	int		counter;
	char	*ptr;
	int		tmp;

	counter = 0;
	linend = 0;
	ret = 1;
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
	{
		free(*line);
		return (-1);
	}
	ptr = *line;
	ret = read(fd, *line, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	(*line)[BUFF_SIZE] = '\0';
	tmp = 0;
	while (linend == 0)
	{
		if ((*line)[tmp] != '\n' && (*line)[tmp] != '\0')
		{
			counter++;
			tmp++;
		}
		else
			linend = 1;
		if (tmp == BUFF_SIZE)
		{
			ft_putstr_len(*line, tmp);	
			ptr = *line;
			free(ptr);
			tmp = 0;
			if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
			{
				free(*line);
				return (-1);
			}
			ret = read(fd, *line, BUFF_SIZE);
			if (ret == -1)
				return (ret);
			(*line)[BUFF_SIZE] = '\0';
		}
	}
	ft_putstr_len(*line, tmp);
	free(*line);
	return (1);
}
