/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/17 20:52:05 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**create_tab(char *str1, char *str2, char *str3)
{
	char	**result;

	result = (char **)malloc(4 * sizeof (char *));
	if (!result)
		exit(1);
	result[0] = ft_strdup(str1);
	result[1] = ft_strdup(str2);
	result[2] = ft_strdup(str3);
	result[3] = NULL;
	if (!result[0] || !result[1] || !result[2])
		exit(1);
	return (result);
}

char	**create_tab2(char *str1)
{
	char	**result;

	result = (char **)malloc(2 * sizeof (char *));
	if (!result)
		exit(1);
	result[0] = ft_strdup(str1);
	result[1] = NULL;
	if (!result[0])
		exit(1);
	return (result);
}

char	**create_tab3()
{
	char	**result;

	result = (char **)malloc(1 * sizeof (char *));
	if (!result)
		exit(1);
	result[0] = NULL;
	return (result);
}

static	int	compare_arrays(char **tab1, char **tab2)
{
	int	i;

	i = 0;
	while (tab1[i])
	{
		if (strcmp(tab1[i], tab2[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	test(int print, char *print_fun, char **my_res, char **real_res)
{
	int     fail;

	if (!my_res || !real_res)
		fail = !(!my_res && !real_res);
	else
		fail = compare_arrays(my_res, real_res);

	if (print >= 2)
	{
		printf("\t-%s: %s\n", print_fun, TEST_RES(fail));
	}
	return (fail);
}

void	free_split(char **tab)
{
	int	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
	}
	free(tab);
}

int	test_ft_split(char *title, int print)
{
	int	failed_tests;
	char	**res1;
	char	**res2;

	if (print >= 1)
	{
		printf("\n%s\n", title);
		printf("==============================\n");
	}
	failed_tests = 0;
	res1 = ft_split("hola mon nocturn!", ' '); 
	res2 = create_tab("hola", "mon", "nocturn!");
	failed_tests += test(print, "test(hola mon nocturn!, )", res1, res2);
	free_split(res1); free_split(res2);
	res1 = ft_split(" hola mon nocturn! ", ' '); 
	res2 = create_tab("hola", "mon", "nocturn!");
	failed_tests += test(print, "test( hola mon nocturn! , )", res1, res2);
	free_split(res1); free_split(res2);
	res1 = ft_split("", 'a'); 
	res2 = create_tab3();
	failed_tests += test(print, "(, a)", res1, res2);
	free_split(res1); free_split(res2);
	res1 = ft_split("hola mon nocturn!", '\0'); 
	res2 = create_tab2("hola mon nocturn!");
	failed_tests += test(print, "test(hola mon nocturn!, \\0)", res1, res2);
	free_split(res1); free_split(res2);
	if (print >= 1)
	{
		if (!failed_tests)
			printf("Result: OK\n");
		else
			printf("Result: FAIL\n");
	}
	return (failed_tests);
}
