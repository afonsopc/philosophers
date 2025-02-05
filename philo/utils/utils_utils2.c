/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:31:07 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 23:34:04 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_utils.h>

char	*utils_strcopy(char *str)
{
	size_t	i;
	char	*new_str;

	new_str = allocs()->calloc(utils()->strlen(str) + 1, sizeof(char));
	i = -1;
	while (new_str && str && str[++i])
		new_str[i] = str[i];
	return (new_str);
}

void	utils_exit(int code)
{
	allocs()->self_free();
	asm(
		"mov $1, %%eax\n"
		"mov %%ebx, %0\n"
		"int $0x80\n"
		:
		: "r" (code)
		: "%eax", "%ebx"
		);
}

ssize_t	utils_fputhex(int fd, unsigned long long n)
{
	char	c;
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 16)
		(utils()->fputnbr)(fd, n / 10);
	c = hex[n % 16];
	return (write(fd, &c, 1));
}

ssize_t	utils_fputptr(int fd, void *ptr)
{
	ssize_t	size;

	if (!ptr)
		return ((utils()->fputstr)(fd, "(nil)"));
	if ((utils()->fputstr)(fd, "0x") < 0)
		return (-1);
	size = (utils()->fputhex)(fd, (unsigned long long)ptr);
	if (size < 0)
		return (-1);
	return (size + 2);
}
