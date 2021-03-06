/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:01:50 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/05 11:24:28 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_memdel(void **ap)
{
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
