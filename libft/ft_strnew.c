/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:18:14 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/10 12:42:15 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	char *return_value;

	return_value = (char*)ft_memalloc(sizeof(char) * size + 1);
	if (return_value)
		return (return_value);
	else
		return (NULL);
}
