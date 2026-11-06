#include "unity.h"
#include "libft.h"
#include <string.h>

void	test_strlen(void)
{
	TEST_ASSERT_EQUAL(strlen(""), ft_strlen(""));
	TEST_ASSERT_EQUAL(strlen("a"), ft_strlen("a"));
	TEST_ASSERT_EQUAL(strlen("hola\0men"), ft_strlen("hola\0men"));
}
