#include "unity.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	helper_strdup(char *str)
{
	char	*res_orig;
	char	*res_mine;

	res_orig = strdup(str);
	if (!res_orig)
		return ;
	res_mine = ft_strdup(str);
	if (!res_mine)
	{
		free(res_orig);
		return ;
	}
	TEST_ASSERT_EQUAL_STRING(res_orig, res_mine);
	free(res_orig);
	free(res_mine);
}

void	test_strdup(void)
{
	helper_strdup("");
	helper_strdup("Helloooo");
}
