#include "unity.h"
#include "libft.h"

void	test_lstclear(void)
{
	t_list	*list;
	t_list	*add;

	// Check function
	list = NULL;
	ft_lstclear(&list, NULL);
	list = ft_lstnew("0");
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_EQUAL_STRING("0", (char *)list->content);
	add = ft_lstnew("1");
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	TEST_ASSERT_EQUAL_STRING("1", (char *)list->content);
	add = ft_lstnew("2");
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	TEST_ASSERT_EQUAL_STRING("2", (char *)list->content);
	ft_lstclear(&list, NULL);
	TEST_ASSERT_NULL(list);
}
