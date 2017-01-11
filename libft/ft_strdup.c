/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:25:04 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/04 14:13:10 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
	char *copy;

	copy = malloc(sizeof(char) * ft_strlen(s1) + 1);
	return (ft_strcpy(copy, s1));
}
