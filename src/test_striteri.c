#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	transformer(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void	helper_striteri(char *s, void (*f)(unsigned int, char *), char *expected)
{
	char	*result;

	result = ft_strdup(s);
	if (!result)
		return ;
	ft_striteri(result, f);
	TEST_ASSERT_EQUAL_STRING(expected, result);
	free(result);
}

void	test_striteri(void)
{
	helper_striteri("", transformer, "");
	helper_striteri("Hola que tal", transformer, "HOLA QUE TAL");
}
