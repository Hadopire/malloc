/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:47:45 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/06 14:14:34 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void *ft_memalloc(size_t size)
{
	char *return_value;

	return_value = malloc(size);
	if (return_value)
	{
		while (size)
			return_value[size-- - 1] = 0;
		return (return_value);
	}
	else
		return (NULL);
}
