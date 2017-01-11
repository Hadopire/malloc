/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:13:44 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/10 16:17:37 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
	long int		return_value;
	int				sign;
	char			nb;

	return_value = 0;
	sign = 1;
	if (!*str)
		return (0);
	while (*str == ' ' || *str == '\f' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = *str == '-' ? -1 : 1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	while ((nb = *str++) >= '0' && nb <= '9')
	{
		return_value *= 10;
		return_value += (int)(nb - '0');
	}
	return ((int)(return_value * sign));
}
