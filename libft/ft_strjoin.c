/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:04:34 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/05 14:19:42 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*return_value;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((return_value = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strcpy(return_value, s1);
	ft_strcat(return_value, s2);
	return_value[len - 1] = '\0';
	return (return_value);
}
