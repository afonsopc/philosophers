/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:11:38 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 23:39:33 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_allocs.h>

t_allocs	*allocs(void)
{
	static t_allocs	allocs;

	return (&allocs);
}

bool	init_allocs(void)
{
	allocs()->calloc = allocs_calloc;
	allocs()->malloc = allocs_malloc;
	allocs()->add_alloc = allocs_add_alloc;
	allocs()->free = allocs_free;
	allocs()->self_free = allocs_self_free;
	allocs()->allocs_print_storage = allocs_print_storage;
	pthread_mutex_init(&allocs()->allocs_mutex, NULL);
	if (USE_ALLOC_STORAGE)
	{
		allocs()->storage = new_alloc_storage();
		if (!allocs()->storage)
			return (false);
	}
	return (true);
}
