/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:33:26 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 23:34:12 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_utils.h>

t_utils	*utils(void)
{
	static t_utils	utils;

	return (&utils);
}

bool	init_utils(void)
{
	utils()->fputstr = utils_fputstr;
	utils()->fputnbr = utils_fputnbr;
	utils()->abs = utils_abs;
	utils()->bzero = utils_bzero;
	utils()->strlen = utils_strlen;
	utils()->strcopy = utils_strcopy;
	utils()->exit = utils_exit;
	utils()->fputhex = utils_fputhex;
	utils()->fputptr = utils_fputptr;
	return (true);
}
