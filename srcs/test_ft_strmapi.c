/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/18 00:52:32 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static char	f_add1(unsigned int i, char c)
{
	i = (unsigned int)c;
	c = i;
	return (c + 1);
}

int	test_ft_strmapi(char *title, int print)
{
	int	failed_tests;
	char	*res;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	res = ft_strmapi("abc", &f_add1); 
	failed_tests += test(print, "test(abc, add1())", res, "bcd"); free(res);
	res = ft_strmapi("", &f_add1); 
	failed_tests += test(print, "test(, add1())", res, ""); free(res);
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
