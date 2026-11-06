#include "unity.h"
#include "libft.h"
#include <string.h>

void	test_strchr(void)
{
	TEST_ASSERT_EQUAL_STRING(strchr("", 'a'), ft_strchr("", 'a'));
	TEST_ASSERT_EQUAL_STRING(strchr("", '\0'), ft_strchr("", '\0'));
	TEST_ASSERT_EQUAL_STRING(strchr("hola", '\0'), ft_strchr("hola", '\0'));
	TEST_ASSERT_EQUAL_STRING(strchr("hola", 'z'), ft_strchr("hola", 'z'));
	TEST_ASSERT_EQUAL_STRING(strchr("holoa", 'o'), ft_strchr("holoa", 'o'));
}

void	test_strrchr(void)
{
	TEST_ASSERT_EQUAL_STRING(strrchr("", 'a'), ft_strrchr("", 'a'));
	TEST_ASSERT_EQUAL_STRING(strrchr("", '\0'), ft_strrchr("", '\0'));
	TEST_ASSERT_EQUAL_STRING(strrchr("hola", '\0'), ft_strrchr("hola", '\0'));
	TEST_ASSERT_EQUAL_STRING(strrchr("hola", 'z'), ft_strrchr("hola", 'z'));
	TEST_ASSERT_EQUAL_STRING(strrchr("holoa", 'o'), ft_strrchr("holoa", 'o'));
}
