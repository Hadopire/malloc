/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:44:40 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/10 11:39:25 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*return_value;
	int		i;

	if (!s)
		return (NULL);
	if ((return_value = ft_strnew(len + 1)) == NULL)
		return (NULL);
	s += start;
	i = 0;
	while (i < (int)len)
		return_value[i++] = *s++;
	return_value[i] = '\0';
	return (return_value);
}
