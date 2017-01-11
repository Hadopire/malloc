/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:16:38 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/06 14:45:06 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;
	int		i;

	if (!(s2_len = ft_strlen(s2)))
		return ((char*)s1);
	if (!n || (int)n < (int)s2_len)
		return (NULL);
	while (*s1 && n)
	{
		i = 0;
		while (s1[i] == s2[i] && s2[i] && i < (int)n)
			i++;
		if (i == (int)s2_len)
			return ((char*)s1);
		s1++;
		n--;
	}
	return (NULL);
}
