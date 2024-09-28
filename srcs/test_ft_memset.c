/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 08:58:20 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int	test(int print, void *s, int c, size_t n)
{
	char	*my_res;
	char	*real_res;
	int	fail;

	my_res = ft_memset(s, c, n);
	real_res = memset(s, c, n);
	fail = memcmp(my_res, real_res, n) != 0;
	
	if (print >= 2)
	{
		printf("\t-test(%s, %c, %lu): %s --> (%s) (%s)\n", 
				(char *)s, c, n, TEST_RES(fail), 
				(char *)my_res, (char *)real_res);
	}
	return (fail);
}
int     test_ft_memset(char *title, int print)
{
	int	failed_tests;
	char	test1[] = "0123456789";
	char	test2[] = "0123456789";
	char	test3[] = "0123456789";

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, test1, 'a', 5);
	failed_tests += test(print, test2, 'b', 0);
	failed_tests += test(print, test3, 'c', 10);

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
