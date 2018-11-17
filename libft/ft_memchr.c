/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:45:16 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 18:32:39 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		cc;
	const unsigned char	*cs;

	cs = (const unsigned char *)s;
	cc = (unsigned char)c;
	while (n)
	{
		if (*cs == cc)
			return ((void *)cs);
		cs++;
		n--;
	}
	return (NULL);
}
