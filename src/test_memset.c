#include "unity.h"
#include "libft.h"
#include <string.h>

void	test_memset(void)
{
	char	str0[9] = "123456789";
	char	str1[9] = "123456789";
	TEST_ASSERT_EQUAL_MEMORY(memset(str0, 'b', 1), ft_memset(str1, 'b', 1), 9);
	TEST_ASSERT_EQUAL_MEMORY(memset(str0, 'c', 9), ft_memset(str1, 'c', 9), 9);
}

void	test_bzero(void)
{
	char	str0[9] = "123456789";
	char	str1[9] = "123456789";

	bzero(str0, 0);
	ft_bzero(str1, 0);
	TEST_ASSERT_EQUAL_MEMORY(str0, str1, 9);
	bzero(str0, 1);
	ft_bzero(str1, 1);
	TEST_ASSERT_EQUAL_MEMORY(str0, str1, 9);
	bzero(str0, 9);
	ft_bzero(str1, 9);
	TEST_ASSERT_EQUAL_MEMORY(str0, str1, 9);
}
