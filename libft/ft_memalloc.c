/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:25:30 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 13:00:07 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *zone;

	zone = NULL;
	if (!(zone = malloc(sizeof(void *) * size)))
		return (NULL);
	ft_bzero(zone, size);
	return (zone);
}
