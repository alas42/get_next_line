/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:55:20 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 18:42:53 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int good;
	char *c;
	int fd;

	if (argc > 5)
		printf("no");
	c = NULL;
	fd = open(argv[1], O_RDONLY);
	good = get_next_line(fd, &c);
	if (good == 1)
		printf("\n5. has been read");
	else if (good == 0)
		printf("\n5. finished");
	else
		printf("\n6. error");
	return (0);
}
