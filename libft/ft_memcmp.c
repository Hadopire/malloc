/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:04:40 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/07 14:51:30 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;
	int					return_value;

	str1 = s1;
	str2 = s2;
	while (n--)
	{
		if ((return_value = (*str1++ - *str2++)))
			return (return_value);
	}
	return (0);
}
