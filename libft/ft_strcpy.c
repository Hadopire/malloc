/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:43:45 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/06 12:47:46 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcpy(char *dst, const char *src)
{
	char *return_value;

	return_value = dst;
	while ((*dst++ = *src++))
		;
	*dst = '\0';
	return (return_value);
}
