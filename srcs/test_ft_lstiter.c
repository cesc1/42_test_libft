/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/19 16:25:36 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>

static void	f(void *content)
{
	int	*num;

	num = (int *)content;
	(*num) += 42;
}

static void	d(void *content)
{	
	printf("%d ", *(int *)content);
}

int	test_ft_lstiter(char *title, int print)
{
	int	failed_tests;
	t_list	*list;
	int	content[] = {0, 1, 2};

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	list = NULL; ft_lstiter(list, &f);
	printf("\t-test with NULL list\n");
	failed_tests += list != NULL;
	printf("\t-test trying to add 42 to the nodes (0, 1, 2): ");
	list = ft_lstnew(&content[0]);
	ft_lstadd_back(&list, ft_lstnew(&content[1]));
	ft_lstadd_back(&list, ft_lstnew(&content[2]));
	ft_lstiter(list, &f);
	failed_tests += (*(int *)list->content != 42) ||\
			(*(int *)list->next->content != 43) ||\
			(*(int *)list->next->next->content != 44);
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
