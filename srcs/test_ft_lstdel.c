/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:22:53 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/19 15:31:00 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_res.h"
#include "libft.h"
#include <stdio.h>

static void	del(void *content)
{
	char	*str;

	str = (char *)content;
	printf("|Deleting ptr with content: %s|", str);
}

static void	test_lstdelone(char *print_text, t_list *list)
{
	printf("%s: ", print_text);
	ft_lstdelone(list, &del);
	printf("\n");
}

static void	test_lstclear(char *print_text, t_list *list)
{
	printf("%s: ", print_text);
	ft_lstclear(&list, &del);
	printf("\n");
}

int     test_ft_lstdel()
{
	t_list	*list;

	printf("\nTEST LISTDELONE LISTCLEAR\n(non testable tests, check by eye)\n");
	printf("==============================\n");

	list = NULL;
	test_lstdelone("Test lstdelone with NULL ptr", list);
	test_lstclear("Test lstclear with NULL ptr", list);
	list = ft_lstnew("Hola");
	test_lstdelone("Test list node Hola", list);
	list = ft_lstnew("Node1");
	ft_lstadd_back(&list, ft_lstnew("Node2"));
	test_lstclear("Test lstclear with 2 nodes", list);

	return (0);
}
