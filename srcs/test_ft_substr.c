/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/16 12:30:44 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	test(int print, char *print_fun, char *my_res, char *real_res)
{
	int	fail;

	if (!my_res || !real_res)
		fail = !(!my_res && !real_res);
	else
		fail = strcmp(my_res, real_res) != 0;

	if (print >= 2)
	{
		printf("\t-%s: %s --> (%s) (%s)\n",
				print_fun, TEST_RES(fail), my_res, real_res);
	}
	return (fail);
}

int     test_ft_substr(char *title, int print)
{
	int	failed_tests;
	char	*res;
	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	res = ft_substr("abcde", 0, 6);
	failed_tests += test(print, "test(abcde, 0, 6)", res, "abcde"); free(res);
	res = ft_substr("abcde", 0, 5);
	failed_tests += test(print, "test(abcde, 0, 5)", res, "abcde"); free(res);
	res = ft_substr("abcde", 0, 4);
	failed_tests += test(print, "test(abcde, 0, 4)", res, "abcd"); free(res);
	res = ft_substr("abcde", 2, 2);
	failed_tests += test(print, "test(abcde, 2, 2)", res, "cd"); free(res);
	res = ft_substr("abcde", 2, 3);
	failed_tests += test(print, "test(abcde, 2, 3)", res, "cde"); free(res);
	res = ft_substr("abcde", 2, 4);
	failed_tests += test(print, "test(abcde, 2, 4)", res, "cde"); free(res);
	res = ft_substr("abcde", 2, 5);
	failed_tests += test(print, "test(abcde, 2, 5)", res, "cde"); free(res);
	res = ft_substr("abcde", 2, 0);
	failed_tests += test(print, "test(abcde, 2, 0)", res, ""); free(res);
	res = ft_substr("abcde", 5, 5);
	failed_tests += test(print, "test(abcde, 5, 5)", res, ""); free(res);
	res = ft_substr("abcde", 10, 1);
	failed_tests += test(print, "test(abcde, 10, 1)", res, ""); free(res);

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
