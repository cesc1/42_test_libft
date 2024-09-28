/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/19 12:23:51 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	test(int print)
{
	int     fail1;
	int	fail2;
	t_list	*list1;
	t_list	*list2;

	fail1 = 0;
	list1 = NULL;
	ft_lstadd_front(&list1, ft_lstnew("Node1"));
	fail1 += strcmp((char *)list1->content, "Node1") != 0;
	if (print >= 2)
		printf("\t-Add node to NULL pointer: %s --> (%s)\n", TEST_RES(fail1), (char *)list1->content);
	fail2 = 0;
	list2 = ft_lstnew("Node1");
	ft_lstadd_front(&list2, ft_lstnew("Node2"));
	fail2 += strcmp((char *)list2->content, "Node2") != 0;
	fail2 += strcmp((char *)list2->next->content, "Node1") != 0;
	if (print >= 2)
		printf("\t-Add node to list: %s --> (%s) (%s)\n", TEST_RES(fail2), (char *)list2->content, (char *)list2->next->content);
	free(list1);
	free(list2->next);
	free(list2);
	return (fail1 || fail2);
}

int	test_ft_lstadd_front(char *title, int print)
{
	int	failed_tests;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print);

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
