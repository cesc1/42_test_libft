#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	test_lstsize(void)
{
	t_list	*list;
	t_list	*add;

	TEST_ASSERT_EQUAL_INT(0, ft_lstsize(NULL));
	list = ft_lstnew("0");
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_EQUAL_INT(1, ft_lstsize(list));
	add = ft_lstnew("1");
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	TEST_ASSERT_EQUAL_INT(2, ft_lstsize(list));
	add = ft_lstnew("2");
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	TEST_ASSERT_EQUAL_INT(3, ft_lstsize(list));
	free(list->next->next);
	free(list->next);
	free(list);
}
