/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:12:39 by ncharret          #+#    #+#             */
/*   Updated: 2016/12/01 18:12:53 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	print_hex(size_t hex)
{
	char hex_chars[16];

	ft_memcpy(hex_chars, "0123456789abcdef", sizeof(char) * 16);
	if (hex > 15u)
	{
		print_hex(hex / 16u);
		print_hex(hex % 16u);
	}
	else
		ft_putchar(hex_chars[hex]);
}
