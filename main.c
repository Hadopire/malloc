/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:44:29 by ncharret          #+#    #+#             */
/*   Updated: 2017/01/11 18:44:31 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "free.h"

t_memory		*get_memory(void)
{
	static t_memory	memory = { 0, 0, 0, NULL };
	size_t			mult;

	if (memory.pagesize == 0)
	{
		memory.pagesize = getpagesize();
		mult = memory.pagesize - 1;
		memory.tiny = (sizeof(t_mem_region) + TINY * 100 + mult) & ~mult;
		memory.small = (sizeof(t_mem_region) + SMALL * 100 + mult) & ~mult;
	}
	return (&memory);
}

void			*get_free_memory(t_mem_region *region, size_t size)
{
	t_mem_block	*block;
	size_t		block_size;
	size_t		largest;

	largest = 0;
	block = region->first_free_block;
	while (block)
	{
		block_size = block->size;
		if (block_size >= size && ISFREE(block->settings))
		{
			block = alloc_block(region, block, size);
			if (block_size == region->largest_free_block)
				update_largest_free_block(block->next, largest, region);
			update_first_free_block(block, region);
			return ((void*)(block + 1));
		}
		if (ISFREE(block->settings))
			largest = block_size > largest ? block_size : largest;
		block = block->next;
	}
	return (NULL);
}

void			*malloc(size_t size)
{
	t_mem_region *region;

	region = get_available_region(size);
	if (region == NULL)
		return (NULL);
	return (get_free_memory(region, size));
}

void			*realloc(void *ptr, size_t size)
{
	void		*return_value;
	t_mem_block	*block;

	if (!ptr)
		return malloc(size);
	block = (t_mem_block*)(ptr - sizeof(t_mem_block));
	if (!ISMAGIC(block->settings) || ISFREE(block->settings))
		return (NULL);
	return_value = malloc(size);
	ft_memcpy(return_value, ptr, size);
	free(ptr);
	return (return_value);
}
