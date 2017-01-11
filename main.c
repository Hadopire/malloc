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
	static t_memory memory = { 0, 0, 0, NULL };
	size_t multiple;

	if (memory.pagesize == 0)
	{
		memory.pagesize = getpagesize();
		multiple = memory.pagesize - 1;
		memory.tiny = (sizeof(t_mem_region) + TINY * 100 + multiple) & ~multiple;
		memory.small = (sizeof(t_mem_region) + SMALL * 100 + multiple) & ~multiple;
	}
	return &memory;
}

// get the needed region size for a specified malloc size
size_t			get_region_size(size_t size)
{
	t_memory *memory;
	size_t multiple;

	memory = get_memory();
	size = size + sizeof(t_mem_block);
	if (size <= TINY)
		return memory->tiny;
	else if(size <= SMALL)
		return memory->small;
	else
	{
		multiple = memory->pagesize - 1;
		return ((size + sizeof(t_mem_region)) + multiple) & ~multiple;
	}
}

void			add_region_to_list(t_mem_region *region)
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
				return;
			}
			region_list = region_list->next;
		}
	}
}

t_mem_region	*create_region(size_t region_size)
{
	t_mem_region *region;
	size_t block_size;

	region = (t_mem_region*)mmap(0, region_size, PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (region == MAP_FAILED)
		return NULL;
	block_size = region_size - sizeof(t_mem_region) - sizeof(t_mem_block);
	region->size = region_size;
	region->largest_free_block = block_size;;
	region->prev = NULL;
	region->next = NULL;
	region->first_free_block = (t_mem_block*)(region + 1);
	region->first_free_block->settings = MAGIC | 0x1;
	region->first_free_block->region = region;
	region->first_free_block->size = block_size;
	region->first_free_block->prev = NULL;
	region->first_free_block->next = NULL;
	add_region_to_list(region);
	return region;
}

t_mem_region	*get_available_region(size_t size)
{
	t_memory *memory;
	t_mem_region *region;
	size_t region_size;

	memory = get_memory();
	region = memory->regions;
	region_size = get_region_size(size);
	while (region)
	{
		if (region->largest_free_block >= size && region_size == region->size)
			return region;
		region = region->next;
	}
	return create_region(region_size);
}

void			update_largest_free_block(t_mem_block *block, size_t largest, t_mem_region *region)
{
	while (block)
	{
		if (ISFREE(block->settings) && block->size > largest)
			largest = block->size;
		block = block->next;
	}
	region->largest_free_block = largest;
}

void 			update_first_free_block(t_mem_block *b, t_mem_region *region)
{
	if (region->largest_free_block == 0)
		region->first_free_block = NULL;
	else if (region->first_free_block == b)
	{
		region->first_free_block = NULL;
		while (b)
		{
			if (ISFREE(b->settings))
			{
				region->first_free_block = b;
				return;
			}
			b = b->next;
		}
	}
}

size_t			get_block_size(t_mem_block *block, t_mem_region *region)
{
	if (block->next)
		return (void*)block->next - ((void*)block + sizeof(t_mem_block));
	else
		return region->size - ((void*)block + sizeof(t_mem_block) - (void*)region - sizeof(t_mem_region));
}

void			*get_free_memory(t_mem_region *region, size_t size)
{
	t_mem_block *block;
	size_t largest;

	largest = 0;
	block = region->first_free_block;
	while (block)
	{
		if (block->size >= size && ISFREE(block->settings))
		{
			if (block->size > ((size + 7) & ~0x7) + sizeof(t_mem_block) + 1)
			{
				block->next = ft_memcpy((void*)block + sizeof(t_mem_block) + ((size + 7) & ~0x7), block, sizeof(t_mem_block));
				block->next->prev = block;
				block->next->size = block->size - ((size+7)&~0x7) - sizeof(t_mem_block);
			}
			if (block->size == region->largest_free_block)
				update_largest_free_block(block->next, largest, region);
			block->size = get_block_size(block, region);
			block->settings ^= 0x1;
			update_first_free_block(block, region);
			return (void*)(block + 1);
		}
		block = block->next;
	}
	return NULL;
}

void			*malloc(size_t size)
{
	t_mem_region *region = get_available_region(size);
	if (region == NULL)
		return NULL;

	return get_free_memory(region, size);
}

void			*realloc(void *ptr, size_t size)
{
	void *return_value;
	t_mem_block *block;


	if (!ptr)
		return (NULL);
	block = (t_mem_block*)(ptr - sizeof(t_mem_block));
	if (!ISMAGIC(block->settings) || ISFREE(block->settings))
		return (NULL);

	return_value = malloc(size);
	ft_memcpy(return_value, ptr, size);
	free(ptr);
	return (return_value);
}

int main()
{
	void *lol = malloc(100);
	free(lol);
	lol = malloc(1000000);
	free(lol);
	malloc(10000);
	malloc(100);
	malloc(100);
	malloc(100);
	lol = malloc(1000000);
	free(lol);
	malloc(10000);
	malloc(1000000);
	lol = malloc(10000);
	free(lol);
	malloc(1000000);
	malloc(10000);

	show_alloc_mem();
}
