#include "unity.h"
#include "libft.h"
#include <stdlib.h>

static void	*f(void *content)
{
	int	*num;
	int	*result;

	result = (int *)malloc(sizeof (int));
	if (!result)
		return (NULL);
	num = (int *)content;
	*result = *num + 1;
	return(result);
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

void	test_lstmap(void)
{
	t_list	*list;
	t_list	*add;
	t_list	*list_result;

	// Check function
	list = create_node_int(0);
	TEST_ASSERT_NOT_NULL(list);
	add = create_node_int(1);
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	add = create_node_int(2);
	TEST_ASSERT_NOT_NULL(add);
	ft_lstadd_front(&list, add);
	list_result = ft_lstmap(list, f, free);
	TEST_ASSERT_NOT_NULL(list_result);
	TEST_ASSERT_EQUAL_INT(2, *((int *)list->content));
	TEST_ASSERT_EQUAL_INT(1, *((int *)list->next->content));
	TEST_ASSERT_EQUAL_INT(0, *((int *)list->next->next->content));
	TEST_ASSERT_NULL(list->next->next->next);
	TEST_ASSERT_EQUAL_INT(3, *((int *)list_result->content));
	TEST_ASSERT_EQUAL_INT(2, *((int *)list_result->next->content));
	TEST_ASSERT_EQUAL_INT(1, *((int *)list_result->next->next->content));
	TEST_ASSERT_NULL(list_result->next->next->next);
	ft_lstclear(&list, free);
	ft_lstclear(&list_result, free);
}
