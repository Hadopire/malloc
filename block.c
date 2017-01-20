/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:44:29 by ncharret          #+#    #+#             */
/*   Updated: 2017/01/11 18:44:31 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			update_largest_free_block(t_mem_block *block,
										size_t largest,
										t_mem_region *region)
{
	while (block)
	{
		if (ISFREE(block->settings) && block->size > largest)
			largest = block->size;
		block = block->next;
	}
	region->largest_free_block = largest;
}

void			update_first_free_block(t_mem_block *b, t_mem_region *region)
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
				return ;
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
		return (region->size -
				((void*)block +
				sizeof(t_mem_block) -
				(void*)region -
				sizeof(t_mem_region)));
}

t_mem_block		*alloc_block(t_mem_region *region,
							t_mem_block *block,
							size_t size)
{
	if (block->size > ((size + 7) & ~0x7) + sizeof(t_mem_block) + 1)
	{
		block->next = ft_memcpy((void*)block +
									sizeof(t_mem_block) +
									((size + 7) &
									~0x7),
								block, sizeof(t_mem_block));
		block->next->prev = block;
		block->next->size = block->size -
							((size + 7) & ~0x7) -
							sizeof(t_mem_block);
	}
	block->size = get_block_size(block, region);
	block->settings ^= 0x1;
	return (block);
}
