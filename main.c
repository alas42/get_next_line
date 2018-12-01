/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:55:20 by avogt             #+#    #+#             */
/*   Updated: 2018/12/01 17:50:37 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./avogt/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*c;
	int		fd;
	int		good;
	int		counter;

	counter = 0;
	fd = open(argv[1], O_RDONLY);
	c = NULL;
	good = 2;
	while (good != -1 && good != 0)
	{
		if (good != 2)
			ft_putchar('\n');
		good = get_next_line(fd, &c);
		dprintf(1, "%s", c);
		ft_strdel(&c);
		counter++;
	}
	return (0);
}
