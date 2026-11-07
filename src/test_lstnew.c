#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	helper_lstnew(void *content, size_t size_content)
{
	t_list	*result;

	result = ft_lstnew(content);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_NULL(result->next);
	TEST_ASSERT_EQUAL_MEMORY(content, result->content, size_content);
	free(result);
}

void	test_lstnew(void)
{
	int	res_num;

	helper_lstnew("", 1);
	helper_lstnew("hola", 5);
	res_num = 5;
	helper_lstnew(&res_num, 4);
}
