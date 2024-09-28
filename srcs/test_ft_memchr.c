/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 15:33:12 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	test(int print, const void *s, char c, size_t n)
{
	void	*my_res;
	void	*real_res;
	int	fail;
	
	my_res = ft_memchr(s, c, n);
	real_res = memchr(s, c, n);
	if (!my_res || !real_res)
		fail = !(!my_res && !real_res);
	else
		fail = memcmp(my_res, real_res, n) != 0;
	if (print >= 2)
	{
		printf("\t-test(%s, %c, %lu): %s --> (%s) (%s)\n",
				(char *)s, c, n, TEST_RES(fail),
				(char *)my_res, (char *)real_res);
	}
	return (fail);
}
int     test_ft_memchr(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, "ale..lea", 'l', 0);
	failed_tests += test(print, "ale..lea", 'l', 1);
	failed_tests += test(print, "ale..lea", 'l', 2);
	failed_tests += test(print, "ale..lea", '.', 8);
	failed_tests += test(print, "ale..lea", '\0', 8);
	failed_tests += test(print, "ale..lea", '\0', 9);
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
