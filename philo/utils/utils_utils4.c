/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:31:07 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/28 21:54:29 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_utils.h>

void	list_print(t_list *list)
{
	size_t	i;

	i = 0;
	while (list)
	{
		(utils()->fputstr)(1, "list[");
		(utils()->fputnbr)(1, i);
		(utils()->fputstr)(1, "]: ");
		(utils()->fputptr)(1, list->data);
		(utils()->fputstr)(1, "\n");
		list = list->next;
		i++;
	}
}
