#include "unity.h"
#include "libft.h"
#include <stdlib.h>

static void	f(void *content)
{
	int	*num;

	num = (int *)content;
	*num += 1;
}

static t_list	*create_node_int(int num)
{
	int		*ptr_num;
	t_list	*result;

	ptr_num = (int *)malloc(sizeof (int));
	if (!ptr_num)
		return (NULL);
	*ptr_num = num;
	result = ft_lstnew(ptr_num);
	if (!result)
		return (free(ptr_num), NULL);
	return (result);
}

void	test_lstiter(void)
{
	t_list	*list;
	t_list	*add;

	// Check function
	list = create_node_int(0);
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_EQUAL_INT(0, *((int *)list->content));
	add = create_node_int(1);
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	TEST_ASSERT_EQUAL_INT(1, *((int *)list->content));
	add = create_node_int(2);
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	TEST_ASSERT_EQUAL_INT(2, *((int *)list->content));
	ft_lstiter(list, f);
	TEST_ASSERT_EQUAL_INT(3, *((int *)list->content));
	TEST_ASSERT_EQUAL_INT(2, *((int *)list->next->content));
	TEST_ASSERT_EQUAL_INT(1, *((int *)list->next->next->content));
	TEST_ASSERT_NULL(list->next->next->next);
	ft_lstclear(&list, free);
}
