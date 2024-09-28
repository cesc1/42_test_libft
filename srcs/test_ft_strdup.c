/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 17:29:08 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	test(int print, const char *s)
{
	char	*my_res;
	char	*real_res;
	int	fail;

	my_res = ft_strdup(s);
	real_res = strdup(s);
	if (!my_res || !real_res)
		fail = !(!my_res && !real_res);
	else
		fail = strcmp(my_res, real_res) != 0;
	if (print >= 2)
	{
		printf("\t-test(%s): %s --> (%s) (%s)\n",
			s, TEST_RES(fail), my_res, real_res);
	}
	free(my_res);
	free(real_res);
	return (fail);
}
int	test_ft_strdup(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, "");
	failed_tests += test(print, "string random");
	failed_tests += test(print, "string\0 random");

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
