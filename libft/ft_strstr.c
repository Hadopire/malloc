/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:52:26 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/06 12:54:20 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	size_t	s2_len;
	int		i;

	if (!(s2_len = ft_strlen(s2)))
		return ((char*)s1);
	while (*s1)
	{
		i = 0;
		while (s1[i] == s2[i] && s2[i])
			i++;
		if (i == (int)s2_len)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
