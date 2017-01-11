/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:43:33 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/06 17:34:22 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	while ((int)len >= 0)
	{
		if (s[len] == (char)c)
			return ((char*)s + len);
		len--;
	}
	return (NULL);
}
