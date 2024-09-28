/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/18 05:57:35 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	test(int print, char *print_fun, t_list *lst_my_res, char *real_res)
{
	int     fail;
	char	*my_res;

	my_res = (char *)lst_my_res->content;
	if (!my_res || !real_res)
		fail = !(!my_res && !real_res);
	else
		fail = strcmp(my_res, real_res) != 0;

	if (print >= 2)
	{
		printf("\t-%s: %s --> (%s) (%s)\n",
			print_fun, TEST_RES(fail), my_res, real_res);
	}
	free(lst_my_res);
	return (fail);
}

int	test_ft_lstnew(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, "test(hola!)", ft_lstnew("hola!"), "hola!");

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
