/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:44:29 by ncharret          #+#    #+#             */
/*   Updated: 2017/01/11 18:44:31 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t				get_region_size(size_t size)
{
	t_memory	*memory;
	size_t		multiple;

	memory = get_memory();
	size = size + sizeof(t_mem_block);
	if (size <= TINY)
		return (memory->tiny);
	else if (size <= SMALL)
		return (memory->small);
	else
	{
		multiple = memory->pagesize - 1;
		return (((size + sizeof(t_mem_region)) + multiple) & ~multiple);
	}
}

void				add_region_to_list(t_mem_region *region)
{
	t_mem_region *region_list;

	region_list = get_memory()->regions;
	if (region_list == NULL)
		get_memory()->regions = region;
	else
	{
		while (region_list)
		{
			if (region_list->next == NULL)
			{
				region_list->next = region;
				region->prev = region_list;
				return ;
			}
			region_list = region_list->next;
		}
	}
}

t_mem_region		*create_region(size_t region_size)
{
	t_mem_region	*region;
	size_t			block_size;

	region = (t_mem_region*)mmap(0, region_size, PROT_WRITE | PROT_READ,
			MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (region == MAP_FAILED)
		return (NULL);
	block_size = region_size - sizeof(t_mem_region) - sizeof(t_mem_block);
	region->size = region_size;
	region->largest_free_block = block_size;
	region->prev = NULL;
	region->next = NULL;
	region->first_free_block = (t_mem_block*)(region + 1);
	region->first_free_block->settings = MAGIC | 0x1;
	region->first_free_block->region = region;
	region->first_free_block->size = block_size;
	region->first_free_block->prev = NULL;
	region->first_free_block->next = NULL;
	add_region_to_list(region);
	return (region);
}

t_mem_region		*get_available_region(size_t size)
{
	t_memory		*memory;
	t_mem_region	*region;
	size_t			region_size;

	memory = get_memory();
	region = memory->regions;
	region_size = get_region_size(size);
	while (region)
	{
		if (region->largest_free_block >= size && region_size == region->size)
			return (region);
		region = region->next;
	}
	return (create_region(region_size));
}
