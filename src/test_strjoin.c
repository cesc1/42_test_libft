#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	helper_strjoin(char const *s1, char const *s2, char *expected)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (!result)
		return ;
	TEST_ASSERT_EQUAL_STRING(result, expected);
	free(result);
}

void	test_strjoin(void)
{
	helper_strjoin("", "", "");
	helper_strjoin("hola", "", "hola");
	helper_strjoin("", "hola", "hola");
	helper_strjoin("0123", "hola", "0123hola");
	helper_strjoin("hola", "0123", "hola0123");
}
