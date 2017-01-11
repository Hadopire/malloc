/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:46:48 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/08 12:56:04 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *buf;

	if (alst)
	{
		buf = *alst;
		while (buf)
		{
			del(buf->content, buf->content_size);
			free(buf);
			buf = buf->next;
		}
		*alst = NULL;
	}
}
