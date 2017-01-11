/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:44:19 by ncharret          #+#    #+#             */
/*   Updated: 2017/01/11 18:45:14 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
#define FREE_H

#include "malloc.h"

void			defrag(t_mem_block *block);
void			release_big(t_mem_block *block);
void			release(t_mem_block *block);
void			free(void *ptr);

#endif
