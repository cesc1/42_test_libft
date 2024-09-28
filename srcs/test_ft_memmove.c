/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/23 09:12:39 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	test(int print, int swap)
{
	char	dest[] = "0123456789";
	char	*dest_ = dest;
	char	*dest1 = strdup(dest);
	char	*dest2 = strdup(dest);
	char	*dest1_free = dest1;
	char	*dest2_free = dest2;
	char	*src = &dest[3];
	char	*src1 = &dest1[3];
	char	*src2 = &dest2[3];
	void	*my_res;
	void	*real_res;
	int	fail;
	int	n = 5;

	if (swap)
	{
		char	*temp;
		temp = dest;
		dest_ = src;
		src = temp;
		temp = dest1;
		dest1 = src1;
		src1 = temp;
		temp = dest2;
		dest2 = src2;
		src2 = temp;
	}

	my_res = ft_memmove((void *)dest1, (void *)src1, n);
	real_res = memmove((void *)dest2, (void *)src2, n);
	fail = (memcmp(my_res, real_res, 10) != 0);
	if (print >= 2)
	{
		printf("\t-test(%s, %s, %d): %s --> (%s) (%s)\n",
				dest_, src, n, TEST_RES(fail), (char *)my_res, (char *)real_res);
	}
	free(dest1_free);
	free(dest2_free);
	return (fail);
}

// Create char *test before using test()
int     test_ft_memmove(char *title, int print)
{
	int	failed_tests;
	
	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	failed_tests += test(print, 0);
	failed_tests += test(print, 1);

	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
