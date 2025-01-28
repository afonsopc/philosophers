/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:31:07 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/28 21:54:29 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_utils.h>

t_list	*utils_list_new(void *data)
{
	t_list	*new;

	new = allocs()->calloc(1, sizeof(t_list));
	new->data = data;
	return (new);
}

void	utils_list_append(t_list **list, void *data)
{
	t_list	*new;
	t_list	*last;

	new = utils()->list_new(data);
	if (!*list)
	{
		*list = new;
		return ;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_list	*utils_list_get(t_list *list, size_t index)
{
	size_t	i;

	i = 0;
	while (list && i < index)
	{
		list = list->next;
		i++;
	}
	return (list);
}

void	utils_list_remove(t_list **list, size_t index)
{
	t_list	*node;
	t_list	*prev_node;

	node = utils()->list_get(*list, index);
	if (!node)
		return ;
	if (index == 0)
	{
		*list = node->next;
		allocs()->free(node);
		return ;
	}
	prev_node = utils()->list_get(*list, index - 1);
	prev_node->next = node->next;
	allocs()->free(node);
}

void	utils_list_free(t_list **list)
{
	t_list	*node;
	t_list	*next;

	node = *list;
	while (node)
	{
		next = node->next;
		allocs()->free(node);
		node = next;
	}
	*list = NULL;
}
