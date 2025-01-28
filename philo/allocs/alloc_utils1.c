/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:23:04 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/16 12:43:44 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_allocs.h>

void	*allocs_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		if (!EXIT_ON_ALLOC_FAIL)
			return (NULL);
		utils()->exit(2);
	}
	if (!allocs()->add_alloc(ptr))
		return (free(ptr), NULL);
	return (ptr);
}

void	*allocs_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > (size_t)-1 / size)
		return (NULL);
	ptr = allocs()->malloc(count * size);
	if (!ptr)
		return (NULL);
	(utils()->bzero)(ptr, count * size);
	return (ptr);
}

t_alloc_storage	*new_alloc_storage(void)
{
	t_alloc_storage	*storage;

	storage = malloc(sizeof(t_alloc_storage));
	if (!storage)
		return (NULL);
	(utils()->bzero)(storage, sizeof(t_alloc_storage));
	return (storage);
}

bool	allocs_add_alloc(void *ptr)
{
	t_alloc_storage	*storage;
	size_t			i;

	storage = allocs()->storage;
	while (USE_ALLOC_STORAGE && storage)
	{
		i = 0;
		while (storage->allocs[i] && i < ALLOC_STORAGE_BUFFER_SIZE)
			i++;
		if (i < ALLOC_STORAGE_BUFFER_SIZE)
		{
			storage->allocs[i] = ptr;
			return (true);
		}
		if (!storage->next)
			storage->next = new_alloc_storage();
		storage = storage->next;
	}
	return (false);
}

void	allocs_free(void *ptr)
{
	t_alloc_storage	*storage;
	size_t			i;

	if (!USE_ALLOC_STORAGE)
		return (free(ptr));
	storage = allocs()->storage;
	while (storage)
	{
		i = 0;
		while (storage->allocs[i] != ptr && i < ALLOC_STORAGE_BUFFER_SIZE)
			i++;
		if (storage->allocs[i] == ptr)
		{
			storage->allocs[i] = NULL;
			return (free(ptr));
		}
		storage = storage->next;
	}
}
