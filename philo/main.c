/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:43:36 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 21:22:56 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc < 5)
		return ((utils()->fputstr)(2, "Error: Not enough arguments\n"), 1);
	write(1, "Hello Philosophers\n", 19);
}
