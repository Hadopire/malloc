/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:19:37 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/07 12:06:30 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s)
{
	size_t	len;
	char	*new_str;

	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	len = ft_strlen((char*)s);
	if ((int)len <= 0)
		return (ft_strnew(1));
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			&& s[len - 1] != '\0' && (int)len > 0)
		len--;
	if (!(new_str = ft_strnew(len + 1)))
		return (NULL);
	new_str = ft_strncpy(new_str, s, len);
	new_str[len] = '\0';
	return (new_str);
}
