/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 16:20:05 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	test(int print, char *print_func, char *res, char *exp_res)
{
	int	fail;

	if (!res || !exp_res)
		fail = !(!res && !exp_res);
	else
		fail = strcmp(res, exp_res) != 0;
	if (print >= 2)
	{
		printf("\t-%s: %s --> (%s) (%s)\n",
			print_func, TEST_RES(fail), res, exp_res);
	}
	return (fail);
}
int     test_ft_strnstr(char *title, int print)
{
	int	failed_tests;
	char	*res;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	res = ft_strnstr("this is the caos of worlds", "is", 27);
	failed_tests += test(print, "test(this is the caos of worlds, is, 27)", 
			res, "is is the caos of worlds");
	res = ft_strnstr("this is the caos of worlds", "is the", 27);
	failed_tests += test(print, "test(this is the caos of worlds, is the, 27)", 
			res, "is the caos of worlds");
	res = ft_strnstr("this is the caos of worlds", "is the", 8);
	failed_tests += test(print, "test(this is the caos of worlds, is the, 8)", 
			res, (void *)0);
	res = ft_strnstr("this is the caos of worlds", "", 27);
	failed_tests += test(print, "test(this is the caos of worlds, , 27)", 
			res, "this is the caos of worlds");
	res = ft_strnstr("this is the caos of worlds", "of", 5);
	failed_tests += test(print, "test(this is the caos of worlds, of, 5)", 
			res, (void *)0);
	res = ft_strnstr("this is the caos of worlds", "the", 10);
	failed_tests += test(print, "test(this is the caos of worlds, the, 10)", 
			res, (void *)0);
	res = ft_strnstr("this is the caos of worlds", "the", 11);
	failed_tests += test(print, "test(this is the caos of worlds, the, 11)", 
			res, "the caos of worlds");
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
