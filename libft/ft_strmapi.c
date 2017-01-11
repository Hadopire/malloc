/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:24:21 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/10 11:53:45 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*return_value;
	int		len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if ((return_value = ft_strnew(len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		return_value[i] = f(i, s[i]);
		i++;
	}
	return (return_value);
}
