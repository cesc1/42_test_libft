/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/16 11:16:24 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

static int	test(int print, int c)
{
	int	my_res;
	int	real_res;
	int	fail;

	my_res = ft_tolower(c);
	real_res = tolower(c);
	fail = my_res != real_res;
	if (print >= 3)
	{
		printf("\t-test(%d): %s --> (%d) (%d)\n",
				c, TEST_RES(fail), my_res, real_res);
	}
	return (fail);
}
int     test_ft_tolower(char *title, int print)
{
	int	failed_tests;
	int	i;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	i = -1;
	while (++i < 256)
	{
		failed_tests += test(print, i);
	}
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
