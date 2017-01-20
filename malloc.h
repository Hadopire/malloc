/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:18:52 by ncharret          #+#    #+#             */
/*   Updated: 2016/12/01 18:18:54 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

# include "libft/libft.h"

# define TINY (1024 + sizeof(t_mem_block))
# define SMALL (10240 + sizeof(t_mem_block))

# define MAGIC 0xdeadbee0
# define ISMAGIC(magic) ((magic & MAGIC) == MAGIC)
# define ISFREE(magic) ((magic & 0x1) == 0x1)

struct s_mem_region;
struct s_mem_block;

typedef struct				s_memory
{
	size_t					pagesize;
	size_t					tiny;
	size_t					small;
	struct s_mem_region		*regions;
}							t_memory;

typedef struct				s_mem_region
{
	size_t					size;
	size_t					largest_free_block;
	struct s_mem_block		*first_free_block;
	struct s_mem_region		*prev;
	struct s_mem_region		*next;
}							t_mem_region;

typedef struct				s_mem_block
{
	int						settings;
	size_t					size;
	struct s_mem_region		*region;
	struct s_mem_block		*prev;
	struct s_mem_block		*next;
}							t_mem_block;

void						print_addr(void *ptr);
void						print_addr_endl(void *ptr);
size_t						print_block(t_mem_block *block);
size_t						print_regions_of_size(t_memory *mem,
												t_mem_region *r,
												size_t size,
												const char *type);
void						show_alloc_mem();
t_memory					*get_memory(void);
void						print_hex(size_t hex);
t_mem_region		*get_available_region(size_t size);
size_t			get_block_size(t_mem_block *block, t_mem_region *region);
void 	  update_first_free_block(t_mem_block *b, t_mem_region *region);
void			update_largest_free_block(t_mem_block *block, size_t largest, t_mem_region *region);
t_mem_block		*alloc_block(t_mem_region *region, t_mem_block *block, size_t size);

#endif
