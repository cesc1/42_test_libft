/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:56:19 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/15 09:02:24 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

static int	test(int c, int print, int my_res, int real_res)
{
	int	fail;

	fail = my_res != real_res;
	if (print >= 3)
	{
		printf("\t-test(%c): %s --> (%d) (%d)\n", 
				c, TEST_RES(fail), my_res, real_res);
	}
	return (fail);
}

static int	test_ft_is(char *title, int print, int (*my_f)(int), int (*real_f)(int))
{
        int     failed_tests;
        int     i;

        if (print >= 1)
        {
                printf("\n%s\n", title);
                printf("==============================\n");
        }
        i = -3;
        failed_tests = 0;
        while (++i < 256)
        {
                failed_tests += test(i, print, my_f(i), real_f(i));
        }
        if (print >= 1)
        {
                if (!failed_tests)
                        printf("Result: OK\n");
                else
                        printf("Result: FAIL\n");
        }
        return (failed_tests);
}

int	test_ft_isalpha(char *title, int print)
{
	return (test_ft_is(title, print, ft_isalpha, isalpha));
}

int	test_ft_isdigit(char *title, int print)
{
	return (test_ft_is(title, print, ft_isdigit, isdigit));
}

int	test_ft_isalnum(char *title, int print)
{
	return (test_ft_is(title, print, ft_isalnum, isalnum));
}

int	test_ft_isascii(char *title, int print)
{
	return (test_ft_is(title, print, ft_isascii, isascii));
}

int	test_ft_isprint(char *title, int print)
{
	return (test_ft_is(title, print, ft_isprint, isprint));
}
