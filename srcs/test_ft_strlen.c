/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:59:31 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 09:03:20 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int	test(char *str, int print)
{
	size_t	my_res;
	size_t	real_res;
	int	fail;

	my_res = ft_strlen(str);
	real_res = strlen(str);
	fail = my_res != real_res;
	if (print >= 2)
	{
		printf("\t-test(%s): %s --> (%lu) (%lu)\n",
				str, TEST_RES(fail), my_res, real_res);
	}
	return (fail);
}

int	test_ft_strlen(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test("", print);
	failed_tests += test("test normal", print);
	failed_tests += test("test \0test", print);
	failed_tests += test("\x90", print);
	failed_tests += test("è", print);

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
