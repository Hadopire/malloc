/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:13:13 by ncharret          #+#    #+#             */
/*   Updated: 2016/12/01 18:19:57 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	print_addr(void *ptr)
{
	ft_putstr("0x");
	print_hex((size_t)ptr);
}

void	print_addr_endl(void *ptr)
{
	print_addr(ptr);
	ft_putchar('\n');
}

size_t	print_block(t_mem_block *block)
{
	print_addr(block + 1);
	ft_putstr(" - ");
	print_addr((void*)block + block->size);
	ft_putstr(" : ");
	ft_putnbr(block->size);
	ft_putendl(" octets");
	return (block->size);
}

size_t	print_regions_of_size(t_memory *mem, t_mem_region *r,
								size_t size, int l, const char *type)
{
	size_t			total_size;
	t_mem_block		*block;

	total_size = 0;
	while (r != NULL)
	{
		if (r->size == size || (l && r->size != mem->small && r->size != mem->tiny))
		{
			ft_putstr(type);
			ft_putstr(" : ");
			print_addr_endl(r);
			block = (t_mem_block*)(r + 1);
			while (block != NULL)
			{
				if (!ISFREE(block->settings))
					total_size += print_block(block);
				block = block->next;
			}
		}
		r = r->next;
	}
	return total_size;
}

void	show_alloc_mem()
{
	t_memory		*mem;
	t_mem_region	*region;
	size_t			total_size;

	mem = get_memory();
	region = mem->regions;
	total_size = 0;

	total_size += print_regions_of_size(mem, region, mem->tiny, 0, "TINY");
	total_size += print_regions_of_size(mem, region, mem->small, 0, "SMALL");
	total_size += print_regions_of_size(mem, region, 0, 1, "LARGE");
	ft_putstr("total size: ");
	ft_putnbr(total_size);
	ft_putendl(" octets");
}

