/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:33:43 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/06 17:13:55 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;

	str = s;
	while (n--)
	{
		if (*str == (char)c)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
