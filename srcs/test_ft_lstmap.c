/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/19 17:32:02 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>

static void	*f(void *content)
{
	int	*num;

	num = (int *)content;
	*num += 42;
	return ((void *)num);
}

static void	d(void *content)
{
	printf("%d ", *(int *)content);
}

int	test_ft_lstmap(char *title, int print)
{
	int	failed_tests;
	t_list	*list;
	t_list	*result;
	int	content[] = {0, 1, 2};

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	list = NULL; result = ft_lstmap(list, &f, &d);
	printf("\t-test with NULL list\n");
	failed_tests += result != NULL;
	printf("\t-test trying to add 42 to the nodes (0, 1, 2): ");
	list = ft_lstnew(&content[0]);
	ft_lstadd_back(&list, ft_lstnew(&content[1]));
	ft_lstadd_back(&list, ft_lstnew(&content[2]));
	result = ft_lstmap(list, &f, &d);
	failed_tests += (*(int *)result->content != 42) ||\
			(*(int *)result->next->content != 43) ||\
			(*(int *)result->next->next->content != 44);
	ft_lstclear(&result, d);
	ft_lstclear(&list, d);
	printf("\n");
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
