#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	test_lstadd_front(void)
{
	t_list	*list;
	t_list	*add;

	list = ft_lstnew("0");
	TEST_ASSERT_NOT_NULL(list);
	add = ft_lstnew("1");
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	add = ft_lstnew("2");
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	TEST_ASSERT_EQUAL_MEMORY(list->content, "2", 1);
	TEST_ASSERT_EQUAL_MEMORY(list->next->content, "1", 1);
	TEST_ASSERT_EQUAL_MEMORY(list->next->next->content, "0", 1);
	TEST_ASSERT_NULL(list->next->next->next);
	free(list->next->next);
	free(list->next);
	free(list);
}
