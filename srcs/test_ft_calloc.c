/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 17:12:18 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static int	test(int print, size_t nmemb, size_t size)
{
	void	*my_res;
	void	*real_res;
	int	fail;

	my_res = ft_calloc(nmemb, size);
	real_res = ft_calloc(nmemb, size);
	if (!my_res || !real_res)
		fail = !(!my_res && !real_res);
	else
		fail = memcmp(my_res, real_res, nmemb * size) != 0;
	if (print >= 2)
	{
		printf("\t-test(%lu, %lu): %s --> (%s) (%s)\n",
				nmemb, size, TEST_RES(fail),
				(char *)my_res, (char *)real_res);
	}
	free(my_res);
	free(real_res);
	return (fail);
}

int     test_ft_calloc(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, 2, 2);
	failed_tests += test(print, 1, 2);
	failed_tests += test(print, 2, 1);
	failed_tests += test(print, 0, 2);
	failed_tests += test(print, 2, 0);
	failed_tests += test(print, ULLONG_MAX/10, 100);

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
