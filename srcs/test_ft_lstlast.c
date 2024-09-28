/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/19 12:54:07 by faguirre         ###   ########.fr       */
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
	{
		fail = strcmp(my_res, real_res) != 0;
	}
	if (print >= 2)
	{
		printf("\t-%s: %s --> (%s) (%s)\n",
			print_fun, TEST_RES(fail), my_res, real_res);
	}
	return (fail);
}

int	test_ft_lstlast(char *title, int print)
{
	int	failed_tests;
	t_list	*list;
	t_list	*result;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	list = NULL; result = ft_lstlast(list);
	failed_tests += test(print, "test(NULL list)", (char *)result, NULL);
	list = ft_lstnew("result"); result = ft_lstlast(list);
	failed_tests += test(print, "test(Test list1)", (char *)result->content, "result");
	ft_lstadd_front(&list, ft_lstnew("Node2")); result = ft_lstlast(list);
	failed_tests += test(print, "test(Test list2)", (char *)result->content, "result");
	free(list->next);
	free(list);
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
