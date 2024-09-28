/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 09:47:05 by faguirre         ###   ########.fr       */
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
static int	test(int print, void *s, size_t n, size_t n_orig)
{
	void	*s1;
	void	*my_res;
	void	*real_res;
	int	fail;

	s1 = (void *)strdup((char *)s); // To modify s
	my_res = (void *)strdup((char *)s);
	real_res = (void *)strdup((char *)s);
	ft_bzero(my_res, n);
	bzero(real_res, n);
	fail = (memcmp(my_res, real_res, n) != 0);
	if (print >= 2)
	{
		printf("\t-test(%s, %lu): %s --> (%s) (%s)\n",
				mem_to_str(s1, n_orig), n, TEST_RES(fail),
				mem_to_str(my_res, n_orig), mem_to_str(real_res, n_orig));
	}
	free(s1);
	free(my_res);
	free(real_res);
	return (fail);
}
int     test_ft_bzero(char *title, int print)
{
	int	failed_tests;
	int	test5 = 17859212;
	int	test6[] = {14123456, 123551235, 123426453, 1235412345, 123455165, 543623456};

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, ((void *)"abcdefghi"), 5, 9);
	failed_tests += test(print, ((void *)"abcdefghi"), 9, 9);
	failed_tests += test(print, ((void *)(&test5)), 2, 3);
	failed_tests += test(print, ((void *)test6), 5, 20);

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
