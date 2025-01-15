/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:33:26 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 21:32:16 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_utils	*utils(void)
{
	static t_utils	utils;

	utils.fputstr = utils_fputstr;
	utils.fputnbr = utils_fputnbr;
	utils.abs = utils_abs;
	utils.bzero = utils_bzero;
	utils.strlen = utils_strlen;
	return (&utils);
}
