/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:43:36 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/16 00:17:58 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
	char	*str;
	size_t	i;

	if (!init(argc, argv))
		return (1);
	i = -1;
	while (++i < 1024 * 10)
		str = utils()->strcopy("Hello Philosophers\n");
	(utils()->fputstr)(1, str);
	utils()->exit(0);
}
