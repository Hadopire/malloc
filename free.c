/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:44:24 by ncharret          #+#    #+#             */
/*   Updated: 2017/01/11 18:44:25 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void			defrag(t_mem_block *block)
{
	if (block->prev && ISFREE(block->prev->settings))
	{
		block->prev->next = block->next;
		block->prev->size = block->size + sizeof(t_mem_block);
		if (block->next)
			block->next->prev = block->prev;
		block = block->prev;
	}
	if (block->next && ISFREE(block->next->settings))
	{
		block->size += block->next->size + sizeof(t_mem_block);
		if (block->next->next)
			block->next->next->prev = block;
		block->next = block->next->next;
	}
	if (block->region->first_free_block > block)
		block->region->first_free_block = block;
	if (block->region->largest_free_block < block->size)
		block->region->largest_free_block = block->size;
}

void			release_big(t_mem_block *block)
{
	if (block->region->prev)
		block->region->prev->next = block->region->next;
	if (block->region->next)
		block->region->next->prev = block->region->prev;
	munmap(block->region, block->region->size);
	return;
}

void			release(t_mem_block *block)
{
	t_memory		*memory;
	t_mem_region	*region;

	memory = get_memory();
	if (block->region->size != memory->tiny &&
		block->region->size != memory->small)
	{
		release_big(block);
		return;
	}
	region = memory->regions;
	while (region)
	{
		if (region->size == block->region->size && region != block->region)
		{
			if (region->prev)
				region->prev->next = region->next;
			if (region->next)
				region->next->prev = region->prev;
			munmap(block->region, block->region->size);
			return;
		}
		region = region->next;
	}
}

void			free(void *ptr)
{
	t_mem_block		*block;

	if (!ptr)
		return;
	block = (t_mem_block*)(ptr - sizeof(t_mem_block));
	if (!ISMAGIC(block->settings) || ISFREE(block->settings))
		return;
	block->settings ^= 0x1;
	defrag(block);
	if (block->size == block->region->size - sizeof(t_mem_region) - sizeof(t_mem_block))
		release(block);
}
