/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:23:44 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/07 14:32:34 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n)
{
	size_t			size;
	long int		buf;
	char			*return_value;

	buf = (long int)n;
	size = n < 0 ? 2 : 1;
	buf = n < 0 ? -buf : buf;
	while ((buf /= 10) >= 1)
		size++;
	if (!(return_value = ft_strnew(sizeof(char) * size + 1)))
		return (NULL);
	buf = (long int)n;
	buf = n < 0 ? -buf : buf;
	while (buf > 9)
	{
		return_value[size - 1] = buf % 10 + '0';
		buf /= 10;
		size--;
	}
	return_value[size - 1] = buf + '0';
	if (size == 2)
		return_value[0] = '-';
	return (return_value);
}
