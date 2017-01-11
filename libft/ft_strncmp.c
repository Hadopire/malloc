/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:32:32 by ncharret          #+#    #+#             */
/*   Updated: 2015/02/20 19:44:05 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *ss1, const char *ss2, size_t n)
{
	unsigned const char *s1;
	unsigned const char *s2;

	s1 = (unsigned char*)ss1;
	s2 = (unsigned char*)ss2;
	if (!n)
		return (0);
	while (n-- > 1 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
