/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:22:06 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 00:58:16 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internal_utils.h>

char	*utils_lltoa(long long n)
{
	char				*str;
	unsigned long long	nbr;
	size_t				size;

	size = utils()->llsize(n);
	str = allocs()->calloc(size + 1, sizeof(char));
	str[size] = 0;
	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nbr)
	{
		str[size-- - 1] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

char	*utils_strjoin2(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = allocs()->calloc(utils()->strlen(s1)
			+ utils()->strlen(s2) + 1, sizeof(char));
	i = -1;
	while (s1 && s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
		str[i + j] = s2[j];
	return (str);
}

char	*utils_strjoin3(char *s1, char *s2, char *s3)
{
	char	*str;
	char	*tmp;

	str = utils()->strjoin2(s1, s2);
	tmp = str;
	str = utils()->strjoin2(str, s3);
	allocs()->free(tmp);
	return (str);
}

char	*utils_strjoin4(char *s1, char *s2, char *s3, char *s4)
{
	char	*str;
	char	*tmp;

	str = utils()->strjoin2(s1, s2);
	tmp = str;
	str = utils()->strjoin3(str, s3, s4);
	allocs()->free(tmp);
	return (str);
}
