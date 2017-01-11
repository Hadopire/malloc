/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:47:37 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/07 12:52:12 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t constsize;
	size_t lendst;
	size_t lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	constsize = size;
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (!size)
		return (lensrc + constsize);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (lendst + lensrc);
}
