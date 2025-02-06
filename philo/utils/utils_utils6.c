/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:22:06 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/06 21:11:54 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_utils.h>

void	utils_sleep_ms(size_t ms)
{
	size_t	start;

	start = utils()->get_time_ms();
	while (utils()->get_time_ms() - start < ms)
		usleep(100);
}

void	utils_safe_sleep_ms(size_t ms, bool *stop)
{
	size_t	start;

	start = utils()->get_time_ms();
	while (utils()->get_time_ms() - start < ms && !*stop)
		usleep(100);
}

static size_t	_utils_llsize(long long n)
{
	if (n == 0)
		return (0);
	if (n < 0)
		return (2 + _utils_llsize(-n / 10));
	return (1 + _utils_llsize(n / 10));
}

size_t	utils_llsize(long long n)
{
	if (n == 0)
		return (1);
	return (_utils_llsize(n));
}
