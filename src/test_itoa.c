#include "unity.h"
#include "libft.h"
#include <stdlib.h>

static void	helper_itoa(int n, char *expected)
{
	char	*result;

	result = ft_itoa(n);
	if (!result)
		return ;
	TEST_ASSERT_EQUAL_STRING(expected, result);
	free(result);
}

void	test_itoa(void)
{
	helper_itoa(0, "0");
	helper_itoa(1, "1");
	helper_itoa(-1, "-1");
	helper_itoa(8, "8");
	helper_itoa(-8, "-8");
	helper_itoa(10, "10");
	helper_itoa(-10, "-10");
	helper_itoa(15123812, "15123812");
	helper_itoa(-15123812, "-15123812");
	helper_itoa(2147483647, "2147483647");
	helper_itoa(-2147483648, "-2147483648");
}
