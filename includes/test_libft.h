/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:15:17 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/19 17:05:10 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LIBFT_H
# define TEST_LIBFT_H

int	test_ft_isalpha(char *title, int print);
int	test_ft_isdigit(char *title, int print);
int	test_ft_isalnum(char *title, int print);
int	test_ft_isascii(char *title, int print);
int	test_ft_isprint(char *title, int print);
int	test_ft_strlen(char *title, int print);
int	test_ft_memset(char *title, int print);
int	test_ft_bzero(char *title, int print);
int	test_ft_memcpy(char *title, int print);
int	test_ft_memmove(char *title, int print);
int	test_ft_strlcpy(char *title, int print);
int	test_ft_strlcat(char *title, int print);
int	test_ft_toupper(char *title, int print);
int	test_ft_tolower(char *title, int print);
int	test_ft_strchr(char *title, int print);
int	test_ft_strrchr(char *title, int print);
int	test_ft_strncmp(char *title, int print);
int	test_ft_memchr(char *title, int print);
int	test_ft_memcmp(char *title, int print);
int	test_ft_strnstr(char *title, int print);
int	test_ft_atoi(char *title, int print);
int	test_ft_calloc(char *title, int print);
int	test_ft_strdup(char *title, int print);
int	test_ft_substr(char *title, int print);
int	test_ft_strjoin(char *title, int print);
int	test_ft_strtrim(char *title, int print);
int	test_ft_split(char *title, int print);
int	test_ft_itoa(char *title, int print);
int	test_ft_strmapi(char *title, int print);
int	test_ft_striteri(char *title, int print);
int	test_ft_put(int print);
int	test_ft_lstnew(char *title, int print);
int	test_ft_lstadd_front(char *title, int print);
int	test_ft_lstsize(char *title, int print);
int	test_ft_lstlast(char *title, int print);
int	test_ft_lstadd_back(char *title, int print);
int	test_ft_lstdelone(char *title, int print);
int	test_ft_lstclear(char *title, int print);
int	test_ft_lstiter(char *title, int print);
int	test_ft_lstmap(char *title, int print);
int	test_ft_lstsize(char *title, int print);
int	test_ft_lstlast(char *title, int print);
int	test_ft_lstadd_back(char *title, int print);
int	test_ft_lstdel();
int	test_ft_lstiter(char *title, int print);
int	test_ft_lstmap(char *title, int print);

#endif
