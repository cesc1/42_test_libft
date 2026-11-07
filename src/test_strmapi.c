#include "unity.h"
#include "libft.h"
#include <stdlib.h>

static char	transformator(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

static void	helper_strmapi(char const *s,
					   char (*f)(unsigned int, char), char *expected)
{
	char	*result;

	result = ft_strmapi(s, f);
	if (!result)
		return ;
	TEST_ASSERT_EQUAL_STRING(expected, result);
	free(result);
}

void	test_strmapi(void)
{
	helper_strmapi("Hola que tal", transformator, "HOLA QUE TAL");
	helper_strmapi("", transformator, "");
}
