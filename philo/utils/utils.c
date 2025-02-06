/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:33:26 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/06 21:12:13 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_utils.h>

t_utils	*utils(void)
{
	static t_utils	utils;

	return (&utils);
}

void	init_utils2(void)
{
	utils()->list_print = utils_list_print;
	utils()->list_get = utils_list_get;
	utils()->is_number = utils_is_number;
	utils()->atoll = utils_atoll;
	utils()->get_time_ms = utils_get_time_ms;
	utils()->llsize = utils_llsize;
	utils()->lltoa = utils_lltoa;
	utils()->strjoin2 = utils_strjoin2;
	utils()->strjoin3 = utils_strjoin3;
	utils()->strjoin4 = utils_strjoin4;
	utils()->sleep_ms = utils_sleep_ms;
	utils()->safe_sleep_ms = utils_safe_sleep_ms;
	utils()->get_time_ms_string = utils_get_time_ms_string;
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
	utils()->list_new = utils_list_new;
	utils()->list_append = utils_list_append;
	utils()->list_remove = utils_list_remove;
	utils()->list_free = utils_list_free;
	init_utils2();
	return (true);
}
