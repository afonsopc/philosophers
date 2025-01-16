/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_allocs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:48:49 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 23:39:23 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_ALLOCS_H
# define INTERNAL_ALLOCS_H

# include <allocs.h>

void			*allocs_calloc(size_t count, size_t size);
bool			allocs_add_alloc(void *ptr);
void			allocs_free(void *ptr);
void			*allocs_malloc(size_t size);
void			allocs_self_free(void);
void			allocs_self_free(void);
void			allocs_print_storage(bool show_nulls);
t_alloc_storage	*new_alloc_storage(void);

#endif