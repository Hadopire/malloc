/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:44:04 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/04 11:35:05 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dstbuf;
	const char	*srcbuf;

	dstbuf = dst;
	srcbuf = src;
	while (n--)
	{
		if ((*(dstbuf++) = *(srcbuf++)) == c)
			return ((unsigned char *)dstbuf);
	}
	return (NULL);
}
