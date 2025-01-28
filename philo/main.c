/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:43:36 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/28 22:02:07 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
Exit Codes:
0 - Success
1 - Not enough arguments
2 - Memory allocation error
*/

bool	init(int argc, char **argv)
{
	(void)argv;
	if (!init_utils())
		return (false);
	if (argc < 5 || argc > 6)
		return ((utils()->fputstr)(2, "Error: Not enough arguments\n"), false);
	if (!init_allocs())
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	size_t	i;
	t_list	*list;

	list = NULL;
	if (!init(argc, argv))
		return (1);
	i = -1;
	while (++i < 1024)
		(utils()->list_append)(&list, utils()->strcopy("Hello Philosophers\n"));
	utils()->list_print(list);
	utils()->exit(0);
}
