/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:15:45 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/07 11:28:07 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncpy(char *dst, const char *src, size_t n)
{
	char *return_value;

	return_value = dst;
	while (n--)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = '\0';
	}
	return (return_value);
}
