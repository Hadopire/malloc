/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:09:06 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/04 11:36:04 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstbuf;
	const char	*srcbuf;

	dstbuf = dst;
	srcbuf = src;
	if (srcbuf <= dstbuf)
	{
		dstbuf += len - 1;
		srcbuf += len - 1;
		while (len--)
		{
			*dstbuf-- = *srcbuf--;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
