/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/17 22:37:06 by faguirre         ###   ########.fr       */
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

int	test_ft_itoa(char *title, int print)
{
	int	failed_tests;
	char	*res;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	res = ft_itoa(42); failed_tests += test(print, "test(42)", res, "42"); free(res);
	res = ft_itoa(-42); failed_tests += test(print, "test(-42)", res, "-42"); free(res);
	res = ft_itoa(0); failed_tests += test(print, "test(0)", res, "0"); free(res);
	res = ft_itoa(-0); failed_tests += test(print, "test(-0)", res, "0"); free(res);
	res = ft_itoa(-2147483648); 
	failed_tests += test(print, "test(-2147483648)", res, "-2147483648"); free(res);


	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
