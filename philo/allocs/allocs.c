/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:11:38 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 21:25:51 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocs.h>

t_allocs	*allocs(void)
{
	static t_allocs	allocs;

	if (!allocs.initialized)
		init_allocs();
	return (&allocs);
}

void	init_allocs(void)
{
	static t_alloc_storage	alloc_storage;

	allocs()->initialized = true;
	allocs()->calloc = allocs_calloc;
	allocs()->malloc = allocs_malloc;
	allocs()->add_alloc = allocs_add_alloc;
	allocs()->free = allocs_free;
	if (USE_ALLOC_STORAGE)
		allocs()->storage = &alloc_storage;
}
