/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/17 20:59:57 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	test(int print, const char *str)
{
	int	my_res;
	int	real_res;
	int	fail;

	my_res = ft_atoi(str);
	real_res = atoi(str);
	fail = my_res != real_res;
	if (print >= 2)
	{
		printf("\t-test(%s): %s --> (%d) (%d)\n",
				str, TEST_RES(fail),
				my_res, real_res);
	}
	return (fail);
}

int     test_ft_atoi(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, "10242");
	failed_tests += test(print, "-10242");
	failed_tests += test(print, "-2147483648");
	failed_tests += test(print, "2147483647");
	failed_tests += test(print, "3000000000");
	failed_tests += test(print, "  42");
	failed_tests += test(print, " \x09\x0a\x0b\x0c\x0d 42");
	failed_tests += test(print, "a42as52");
	failed_tests += test(print, " 42a2123");
	failed_tests += test(print, "+42a2123");
	failed_tests += test(print, "--42a2123");
	failed_tests += test(print, "++42a2123");
	failed_tests += test(print, "+-42a2123");

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
