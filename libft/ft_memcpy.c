/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:33:35 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/06 15:19:00 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstbuf;
	const char	*srcbuf;

	dstbuf = dst;
	srcbuf = src;
	while (n--)
		*(dstbuf++) = *(srcbuf++);
	return (dst);
}
