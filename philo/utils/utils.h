/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:48:49 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/28 21:54:29 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdbool.h>
# include <allocs.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_utils
{
	ssize_t				(*fputstr)(int fd, char *s);
	ssize_t				(*fputnbr)(int fd, long long n);
	size_t				(*strlen)(char *str);
	unsigned long long	(*abs)(long long n);
	void				(*bzero)(void *s, size_t n);
	char				*(*strcopy)(char *str);
	void				(*exit)(int code);
	ssize_t				(*fputhex)(int fd, unsigned long long n);
	ssize_t				(*fputptr)(int fd, void *ptr);
	t_list				*(*list_new)(void *data);
	void				(*list_append)(t_list **list, void *data);
	void				(*list_remove)(t_list **list, size_t index);
	void				(*list_free)(t_list **list);
	void				(*list_print)(t_list *list);
	t_list				*(*list_get)(t_list *list, size_t index);
}	t_utils;

t_utils				*utils(void);
bool				init_utils(void);

#endif