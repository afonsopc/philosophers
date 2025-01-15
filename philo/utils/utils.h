/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:48:49 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 21:32:09 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <allocs.h>

typedef struct s_utils
{
	ssize_t				(*fputstr)(int fd, char *s);
	ssize_t				(*fputnbr)(int fd, long long n);
	size_t				(*strlen)(char *str);
	unsigned long long	(*abs)(long long n);
	void				(*bzero)(void *s, size_t n);
	void				*(*calloc)(size_t count, size_t size);
	void				(*free)(void *ptr);
}	t_utils;

t_utils				*utils(void);
ssize_t				utils_fputstr(int fd, char *s);
ssize_t				utils_fputnbr(int fd, long long n);
unsigned long long	utils_abs(long long n);
void				utils_bzero(void *s, size_t n);
size_t				utils_strlen(char *str);

#endif