/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 14:44:01 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	test(int print, const char *s, int c)
{
	char	*my_res;
	char	*real_res;
	int	fail;

	my_res = ft_strrchr(s, c);
	real_res = strrchr(s, c);
	fail = strcmp(my_res, real_res) != 0;
	if (print >= 2)
	{
		printf("\t-test(%s, %c): %s --> (%s) (%s)\n",
				s, c, TEST_RES(fail),
				my_res, real_res);
	}
	return (fail);
}
int     test_ft_strrchr(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, "ale..lea", 'l');
	failed_tests += test(print, "ale..lea", '.');
	failed_tests += test(print, "ale..lea", '\0');

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
