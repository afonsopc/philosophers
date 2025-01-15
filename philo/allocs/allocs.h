/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:48:49 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 21:25:49 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCS_H
# define ALLOCS_H

# include <unistd.h>
# include <utils.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef ALLOC_STORAGE_BUFFER_SIZE
#  define ALLOC_STORAGE_BUFFER_SIZE 5120
# endif

# ifndef USE_ALLOC_STORAGE
#  define USE_ALLOC_STORAGE 1
# endif

typedef struct s_alloc_storage
{
	void					*allocs[ALLOC_STORAGE_BUFFER_SIZE];
	struct s_alloc_storage	*next;
}	t_alloc_storage;

typedef struct s_allocs
{
	bool					initialized;
	t_alloc_storage			*storage;
	void					*(*calloc)(size_t count, size_t size);
	void					*(*malloc)(size_t size);
	void					(*free)(void *ptr);
	bool					(*add_alloc)(void *ptr);
}	t_allocs;

t_allocs	*allocs(void);
void		init_allocs(void);
void		*allocs_calloc(size_t count, size_t size);
bool		allocs_add_alloc(void *ptr);
void		allocs_free(void *ptr);
void		*allocs_malloc(size_t size);

#endif