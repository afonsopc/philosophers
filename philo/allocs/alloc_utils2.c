/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:23:04 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 23:52:00 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_allocs.h>

static void	free_alloc_storage(t_alloc_storage *storage)
{
	size_t	i;

	i = -1;
	while (++i < ALLOC_STORAGE_BUFFER_SIZE)
	{
		free(storage->allocs[i]);
		storage->allocs[i] = NULL;
	}
	free(storage);
}

void	allocs_self_free(void)
{
	t_alloc_storage	*storage;
	t_alloc_storage	*tmp;

	if (!USE_ALLOC_STORAGE)
		return ;
	storage = allocs()->storage;
	while (storage)
	{
		tmp = storage->next;
		free_alloc_storage(storage);
		storage = tmp;
	}
	pthread_mutex_destroy(&allocs()->allocs_mutex);
}

void	allocs_print_storage(bool show_nulls)
{
	t_alloc_storage	*storage;
	size_t			i;
	size_t			j;

	if (!USE_ALLOC_STORAGE)
		return ((utils()->fputstr)(1, "ALLOC STORAGE is not active\n"),
			(void)0);
	storage = allocs()->storage;
	j = -1;
	while (storage && (++j + 1))
	{
		i = -1;
		while (++i < ALLOC_STORAGE_BUFFER_SIZE)
		{
			if ((show_nulls && !storage->allocs[i]) || storage->allocs[i])
			{
				((utils()->fputstr)(1, "storage["), (utils()->fputnbr)(1, j));
				((utils()->fputstr)(1, "]["), (utils()->fputnbr)(1, i));
				(utils()->fputstr)(1, "]: ");
				(utils()->fputptr)(1, storage->allocs[i]);
				(utils()->fputstr)(1, "\n");
			}
		}
		storage = storage->next;
	}
}
