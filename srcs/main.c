/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:21:39 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/19 10:49:15 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include <stdio.h>
#include <stdlib.h>

int	is_passed(int *result, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (result[i] > 0)
		{
			return (0);
		}
	}
	return (1);
}

int	main(void)
{
	int	print = 2;
	int	result[] = 
	{
		test_ft_isalpha("TEST ft_isalpha", print),
		test_ft_isdigit("TEST ft_isdigit", print),
		test_ft_isalnum("TEST ft_isalnum", print),
		test_ft_isascii("TEST ft_isascii", print),
		test_ft_isprint("TEST ft_isprint", print),
		test_ft_strlen("TEST ft_strlen", print),
		test_ft_memset("TEST ft_memset", print),
		test_ft_bzero("TEST ft_bzero", print),
		test_ft_memcpy("TEST ft_memcpy", print),
		test_ft_memmove("TEST ft_memmove", print),
		test_ft_strlcpy("TEST ft_strlcpy", print),
		test_ft_strlcat("TEST ft_strlcat", print),
		test_ft_toupper("TEST ft_toupper", print),
		test_ft_tolower("TEST ft_tolower", print),
		test_ft_strchr("TEST ft_strchr", print),
		test_ft_strrchr("TEST ft_strrchr", print),
		test_ft_strncmp("TEST ft_strncmp", print),
		test_ft_memchr("TEST ft_memchr", print),
		test_ft_memcmp("TEST ft_memcmp", print),
		test_ft_strnstr("TEST ft_strnstr", print),
		test_ft_atoi("TEST ft_atoi", print),
		test_ft_calloc("TEST ft_calloc", print),
		test_ft_strdup("TEST ft_strdup", print),
		test_ft_substr("TEST ft_substr", print),
		test_ft_strjoin("TEST ft_strjoin", print),
		test_ft_strtrim("TEST ft_strtrim", print),
		test_ft_split("TEST ft_split", print),
		test_ft_itoa("TEST ft_itoa", print),
		test_ft_strmapi("TEST ft_strmapi", print),
		test_ft_striteri("TEST ft_striteri", print),
		test_ft_put(print)
	};
	size_t	n = sizeof(result) / sizeof(result[0]);

	printf("\n");
	if (is_passed(result, n))
	{
		printf("====================\n");
		printf("ALL TESTS PASSED! :)\n");
		printf("====================\n");
	}
	else
	{
		printf("===============\n");
		printf("FAILED TESTS :(\n");
		printf("===============\n");

	}
	return (0);
}
