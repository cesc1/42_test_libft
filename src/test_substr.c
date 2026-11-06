#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	helper_substr(char const *s, unsigned int start, size_t len,
					  char *res_orig)
{
	char	*res_mine;

	res_mine = ft_substr(s, start, len);
	if (!res_orig || !res_mine)
	{
		TEST_ASSERT_EQUAL_PTR(res_orig, res_mine);
		free(res_mine);
		return ;
	}
	TEST_ASSERT_EQUAL_STRING(res_orig, res_mine);
	free(res_mine);
}

void	test_substr(void)
{
	// Empty
	helper_substr("", 0, 0, "");
	helper_substr("", 0, 1, "");
	helper_substr("", 1, 1, "");
	// Start after finish
	helper_substr("Hola", 3, 5, "a");
	helper_substr("Hola", 4, 5, "");
	helper_substr("Hola", 5, 5, "");
	// 0 Length
	helper_substr("Hola", 0, 0, "");
	helper_substr("Hola", 1, 0, "");
	// True substr
	helper_substr("0123456", 3, 0, "");
	helper_substr("0123456", 3, 1, "3");
	helper_substr("0123456", 3, 2, "34");
	helper_substr("0123456", 3, 3, "345");
	helper_substr("0123456", 3, 4, "3456");
	helper_substr("0123456", 3, 5, "3456");

}
