/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/16 15:57:31 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	test(int print, char *print_func, size_t res, size_t exp_res,
		       	char *dest, char *exp_dest)
{
	int	fail;
	int	fail1;
	int	fail2;

	fail1 = res != exp_res;
	fail2 = strcmp(dest, exp_dest) != 0;
	fail = fail1 || fail2;
	if (print >= 2)
	{
		printf("\t-%s: %s --> (%lu) (%lu) (%s) (%s)\n",
				print_func, TEST_RES(fail), res, exp_res, dest, exp_dest);
	}
	return (fail);
}
int     test_ft_strlcat(char *title, int print)
{
	int	failed_tests;
	char *testa = "hola \0..........";
	char *test0 = strdup(testa);
	char *test1 = strdup(testa);
	char *test2 = strdup(testa);
	char *test3 = strdup(testa);
	unsigned long	res;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	res = ft_strlcat(test0, "mundo", 4);
	failed_tests += test(print, "test(hola , mundo, 4)", res, 4 + 5, test0, "hola ");
	res = ft_strlcat(test1, "mundo", 12);
	failed_tests += test(print, "test(hola , mundo, 12)", res, 5 + 5, test1, "hola mundo");
	res = ft_strlcat(test2, "mundo", 11);
	failed_tests += test(print, "test(hola , mundo, 11)", res, 5 + 5, test2, "hola mundo");
	res = ft_strlcat(test3, "mundo", 10);
	failed_tests += test(print, "test(hola , mundo, 10)", res, 5 + 5, test3, "hola mund");
	free(test0);
	free(test1);
	free(test2);
	free(test3);
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
