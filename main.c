/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:02:08 by avogt             #+#    #+#             */
/*   Updated: 2019/02/07 16:41:33 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char *line;

	(void)ac;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	ret = 1;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
//		ft_putstr("line = #");
//		ft_putendl(line);
		free(line);
	}
	ft_strdel(&line);
	close(fd);
	return (0);
}
