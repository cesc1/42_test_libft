/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/16 18:58:00 by faguirre         ###   ########.fr       */
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

int	test_ft_strtrim(char *title, int print)
{
	int	failed_tests;
	char	*res;
	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	res = ft_strtrim("abacacbdefg", "abc");
	failed_tests += test(print, "test(abacacbdefg, abc)", res, "defg");free(res);
	res = ft_strtrim("abacacbdefg", "ab");
	failed_tests += test(print, "test(abacacbdefg, ab)", res, "cacbdefg");free(res);
	res = ft_strtrim("abcacbdefg", "abcdefg");
	failed_tests += test(print, "test(abcacbdefg, abcdefg)", res, "");free(res);
	res = ft_strtrim("abc", "");failed_tests += test(print, "test(abc,)", res, "abc");free(res);
	res = ft_strtrim("", "");failed_tests += test(print, "test(,)", res, "");free(res);

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
