#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	test_calloc(void)
{
	void	*orig;
	void	*mine;

	orig = calloc(100, 100);
	if (!orig)
		return ;
	mine = ft_calloc(100, 100);
	if (!mine)
	{
		free(orig);
		return ;
	}
	TEST_ASSERT_EQUAL_MEMORY(orig, mine, 100 * 100);
	free(orig);
	free(mine);
}
