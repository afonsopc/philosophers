/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:48:49 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 23:43:31 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCS_H
# define ALLOCS_H

# include <unistd.h>
# include <utils.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef ALLOC_STORAGE_BUFFER_SIZE
#  define ALLOC_STORAGE_BUFFER_SIZE 50
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
	void					(*self_free)(void);
	void					(*allocs_print_storage)(bool show_nulls);
}	t_allocs;

t_allocs		*allocs(void);
bool			init_allocs(void);

#endif