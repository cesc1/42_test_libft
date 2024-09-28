/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 11:18:53 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static unsigned char	*mem_to_str(const void *mem, size_t n)
{
	size_t	i;
	unsigned char	*mem_c;

	mem_c = (unsigned char *)mem;
	i = 0;
	while (i < n)
	{
		if (mem_c[i] == 0)
		{
			mem_c[i] = '0';
		}
		i++;
	}
	mem_c[i] = '\0';
	return (mem_c);
}

// Reservar memoria para n + 1
static int	test(int print, void *dest, const void *src, size_t n,
		size_t n_dest, size_t n_srcs)
{
	void	*dest_c;
	void	*src_c;
	void	*my_res;
	void	*real_res;
	int	fail;

	dest_c = (void *)strdup((char *)dest);
	src_c = (void *)strdup((char *)src);
	my_res = (void *)strdup((char *)dest);
	real_res = (void *)strdup((char *)dest);
	ft_memcpy(my_res, src, n);
	memcpy(real_res, src, n);
	fail = (memcmp(my_res, real_res, n_dest) != 0);
	if (print >= 2)
	{
		printf("\t-test(%s, %s, %lu): %s --> (%s) (%s)\n",
				mem_to_str(dest_c, n_dest), mem_to_str(src_c, n_srcs), n,
				TEST_RES(fail),
				mem_to_str(my_res, n_dest), mem_to_str(real_res, n_dest));
	}
	free(dest_c);
	free(src_c);
	free(my_res);
	free(real_res);
	return (fail);
}
int     test_ft_memcpy(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, (void *)".........", (void *)"hola", 5, 9, 5);
	failed_tests += test(print, (void *)".........", (void *)"hola", 4, 9, 5);
	failed_tests += test(print, (void *)".........", (void *)"hola", 3, 9, 5);
	failed_tests += test(print, (void *)".........", (void *)"hola", 0, 9, 5);

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
