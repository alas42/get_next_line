/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:22:32 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 12:53:43 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	lendest;
	size_t	i;

	lendest = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[lendest + i] = s2[i];
		i++;
	}
	s1[lendest + i] = '\0';
	return (s1);
}
