/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/18 03:42:46 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

static void	test_putchar_fd(int print, char c, char c_real)
{
	if (print >= 1)
	{
		printf("\t-test(%c): ", c);
		ft_putchar_fd(c, 1);
		printf("(%c)\n", c_real);
	}
}

static void	test_putstr_fd(int print, char *str, char *str_real)
{
	if (print >= 1)
	{
		printf("\t-test(%s): ", str);
		ft_putstr_fd(str, 1);
		printf("(%s)\n", str_real);
	}
}

static void	test_putendl_fd(int print, char *str, char *str_real)
{
	if (print >= 1)
	{
		printf("\t-test(%s): ", str);
		ft_putendl_fd(str, 1);
		printf("(%s)\n", str_real);
	}
}

static void	test_putnbr_fd(int print, int n, char *str_real)
{
	if (print >= 1)
	{
		printf("\t-test(%d): ", n);
		ft_putnbr_fd(n, 1);
		printf("(%s)\n", str_real);
	}
}

int     test_ft_put(int print)
{
	if (print >= 1)
	{
		printf("\nTEST PUT\n(non testable tests, check by eye)\n");
		printf("==============================\n");
	}
	printf("Test putchar_fd:\n");
	test_putchar_fd(print, 'a', 'a');
	printf("Test putstr_fd:\n");
	test_putstr_fd(print, "hola", "hola");
	printf("Test putendl_fd:\n");
	test_putendl_fd(print, "hola", "hola\n");
	printf("Test putnbr_fd:\n");
	test_putnbr_fd(print, 42, "42");
	test_putnbr_fd(print, -42, "-42");
	test_putnbr_fd(print, -2147483648, "-2147483648");
	printf("\n");
	return (0);
}
