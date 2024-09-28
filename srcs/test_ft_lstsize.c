/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/19 11:33:13 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	test(int print, char *print_fun, int my_res, int real_res)
{
	int     fail;

	fail = my_res != real_res;
	if (print >= 2)
	{
		printf("\t-%s: %s --> (%d) (%d)\n",
			print_fun, TEST_RES(fail), my_res, real_res);
	}
	return (fail);
}

int	test_ft_lstsize(char *title, int print)
{
	int	failed_tests;
	t_list	*list;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	list = NULL;
	failed_tests += test(print, "test(empty list)", ft_lstsize(list), 0);
	ft_lstadd_front(&list, ft_lstnew("add 1"));
	failed_tests += test(print, "test(list1)", ft_lstsize(list), 1);
	ft_lstadd_front(&list, ft_lstnew("add 2"));
	failed_tests += test(print, "test(list2)", ft_lstsize(list), 2);
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
