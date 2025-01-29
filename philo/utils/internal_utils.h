/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:48:49 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 08:39:32 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_UTILS_H
# define INTERNAL_UTILS_H

# include <utils.h>

ssize_t				utils_fputstr(int fd, char *s);
ssize_t				utils_fputnbr(int fd, long long n);
unsigned long long	utils_abs(long long n);
void				utils_bzero(void *s, size_t n);
size_t				utils_strlen(char *str);
char				*utils_strcopy(char *str);
void				utils_exit(int code);
ssize_t				utils_fputhex(int fd, unsigned long long n);
ssize_t				utils_fputptr(int fd, void *n);
t_list				*utils_list_new(void *data);
void				utils_list_append(t_list **list, void *data);
t_list				*utils_list_get(t_list *list, size_t index);
void				utils_list_remove(t_list **list, size_t index);
void				utils_list_free(t_list **list);
void				utils_list_print(t_list *list);
bool				utils_is_number(char *str);
long long			utils_atoll(char *str);
size_t				utils_get_time_ms(void);
size_t				utils_llsize(long long n);
char				*utils_lltoa(long long n);
char				*utils_strjoin2(char *s1, char *s2);
char				*utils_strjoin3(char *s1, char *s2, char *s3);
char				*utils_strjoin4(char *s1, char *s2, char *s3, char *s4);
void				utils_sleep_ms(size_t ms);
char				*utils_get_time_ms_string(size_t epoch);

#endif