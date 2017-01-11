/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:59:33 by ncharret          #+#    #+#             */
/*   Updated: 2015/02/20 19:40:13 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int c, int fd)
{
	if (c == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (c < 0)
	{
		ft_putchar_fd('-', fd);
		c *= -1;
	}
	if (c > 9)
	{
		ft_putnbr_fd(c / 10, fd);
		ft_putnbr_fd(c % 10, fd);
	}
	else
		ft_putchar_fd(c + '0', fd);
}
