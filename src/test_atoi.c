#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	test_atoi(void)
{
	// empty and 0
	TEST_ASSERT_EQUAL_INT(atoi(""), ft_atoi(""));
	TEST_ASSERT_EQUAL_INT(atoi("-"), ft_atoi("-"));
	TEST_ASSERT_EQUAL_INT(atoi("a23-"), ft_atoi("a23-"));
	TEST_ASSERT_EQUAL_INT(atoi("  a23-"), ft_atoi("  a23-"));
	TEST_ASSERT_EQUAL_INT(atoi("-"), ft_atoi("-"));
	TEST_ASSERT_EQUAL_INT(atoi("0000"), ft_atoi("0000"));
	// spaces
	TEST_ASSERT_EQUAL_INT(atoi(" \t\r\n-52"), ft_atoi(" \t\r\n-52"));
	// num
	TEST_ASSERT_EQUAL_INT(atoi("-523"), ft_atoi("-523"));
	TEST_ASSERT_EQUAL_INT(atoi("+523"), ft_atoi("+523"));
	TEST_ASSERT_EQUAL_INT(atoi("523"), ft_atoi("523"));
	TEST_ASSERT_EQUAL_INT(atoi("0523"), ft_atoi("0523"));
	TEST_ASSERT_EQUAL_INT(atoi(" +523a2"), ft_atoi(" +523a2"));
	// Limits
	TEST_ASSERT_EQUAL_INT(atoi(" 2147483647"), ft_atoi(" 2147483647"));
	TEST_ASSERT_EQUAL_INT(atoi("-2147483648"), ft_atoi("-2147483648"));
	// Signs
	TEST_ASSERT_EQUAL_INT(atoi("--523"), ft_atoi("--523"));
	TEST_ASSERT_EQUAL_INT(atoi("++523"), ft_atoi("++523"));
	TEST_ASSERT_EQUAL_INT(atoi("+-523"), ft_atoi("+-523"));
	TEST_ASSERT_EQUAL_INT(atoi("-+523"), ft_atoi("-+523"));
	TEST_ASSERT_EQUAL_INT(atoi("-523+5"), ft_atoi("-523+5"));

}
