/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:17:08 by ncharret          #+#    #+#             */
/*   Updated: 2014/11/08 14:17:27 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *buf;
	t_list *fresh_list;
	t_list *value;
	t_list *return_value;

	if (lst)
	{
		buf = f(lst);
		if (!(fresh_list = ft_lstnew(buf->content, buf->content_size)))
			return (NULL);
		return_value = fresh_list;
		lst = lst->next;
		while (lst)
		{
			buf = f(lst);
			if (!(value = ft_lstnew(buf->content, buf->content_size)))
				return (NULL);
			fresh_list->next = value;
			fresh_list = fresh_list->next;
			lst = lst->next;
		}
		return (return_value);
	}
	return (NULL);
}
