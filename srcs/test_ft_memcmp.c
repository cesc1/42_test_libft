/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 15:43:50 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	test(int print, const void *s1, const void *s2, size_t n)
{
	int	my_res;
	int	real_res;
	int	fail;
	
	my_res = ft_memcmp(s1, s2, n);
	real_res = memcmp(s1, s2, n);
	fail = my_res != real_res;
	if (print >= 2)
	{
		printf("\t-test(%s, %s, %lu): %s --> (%d) (%d)\n",
				(char *)s1, (char *)s2, n, TEST_RES(fail),
				my_res, real_res);
	}
	return (fail);
}
int     test_ft_memcmp(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, "a", "a", 0);
	failed_tests += test(print, "a", "b", 0);
	failed_tests += test(print, "aab", "aaa", 4);
	failed_tests += test(print, "aaa", "aab", 4);
	failed_tests += test(print, "aaa", "aab", 3);
	failed_tests += test(print, "aaa", "aab", 2);
	failed_tests += test(print, "aa", "aab", 3);
	failed_tests += test(print, "aab", "aa", 3);
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
