/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/16 19:05:06 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	test(int print, char *print_fun, char *my_res, char *real_res)
{
	int     fail;

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

int	test_ft_strjoin(char *title, int print)
{
	int	failed_tests;
	char	*res;
	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	res = ft_strjoin("hola ", "world!");
	failed_tests += test(print, "test(hola , world!)", res, "hola world!"); free(res);
	res = ft_strjoin("", "world!");
	failed_tests += test(print, "test(,world!)", res, "world!"); free(res);
	res = ft_strjoin("hola", "");
	failed_tests += test(print, "test(hola,)", res, "hola"); free(res);
	res = ft_strjoin("", "");
	failed_tests += test(print, "test(,)", res, ""); free(res);
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
