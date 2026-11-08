#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	test_lstlast(void)
{
	t_list	*list;
	t_list	*add;

	TEST_ASSERT_EQUAL_INT(0, ft_lstsize(NULL));
	list = ft_lstnew("0");
	TEST_ASSERT_NOT_NULL(list);
	add = ft_lstnew("1");
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	add = ft_lstnew("2");
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	TEST_ASSERT_EQUAL_STRING("0", (char *)ft_lstlast(list)->content);
	free(list->next->next);
	free(list->next);
	free(list);
}
