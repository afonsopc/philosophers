/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:31:07 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 21:32:34 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

ssize_t	utils_fputstr(int fd, char *s)
{
	return (write(fd, s, utils()->strlen(s)));
}

ssize_t	utils_fputnbr(int fd, long long n)
{
	char				c;
	unsigned long long	nbr;

	if (n < 0)
		write(fd, "-", 1);
	nbr = utils()->abs(n);
	if (nbr > 9)
		(utils()->fputnbr)(fd, n / 10);
	c = nbr % 10 + '0';
	return (write(fd, &c, 1));
}

unsigned long long	utils_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	utils_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		ptr[n - 1] = 0;
		n--;
	}
}

size_t	utils_strlen(char *str)
{
	size_t	size;

	size = 0;
	while (str && str[size])
		size++;
	return (size);
}
