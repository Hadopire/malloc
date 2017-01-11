/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:51:47 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/08 14:17:17 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *return_value;

	if (!(return_value = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		return_value->content = ft_memalloc(content_size);
		ft_memcpy(return_value->content, content, content_size);
		ft_memcpy(&return_value->content_size, &content_size, sizeof(size_t));
	}
	else
	{
		return_value->content = NULL;
		return_value->content_size = 0;
	}
	return_value->next = NULL;
	return (return_value);
}
