#include "unity.h"
#include "libft.h"
#include <ctype.h>

void	test_toupper(void)
{
	int	i;

	i -11;
	while (++i < 256)
		TEST_ASSERT_EQUAL(toupper(i), ft_toupper(i));
}

void	test_tolower(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		TEST_ASSERT_EQUAL(tolower(i), ft_tolower(i));
}
