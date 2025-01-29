/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:31:07 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 08:39:40 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_utils.h>

void	utils_list_print(t_list *list)
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

bool	utils_is_number(char *str)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

long long	utils_atoll(char *str)
{
	long long	n;

	n = 0;
	while (*str)
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (n);
}

size_t	utils_get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

char	*utils_get_time_ms_string(size_t epoch)
{
	char	*str;
	size_t	time;

	time = utils()->get_time_ms();
	time -= epoch;
	str = utils()->lltoa(time);
	return (str);
}
