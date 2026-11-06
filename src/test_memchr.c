#include "unity.h"
#include "libft.h"
#include <string.h>

static void	helper_memchr(const void *s, int c, size_t n)
{
	void	*res0;
	void	*res1;

	res0 = memchr(s, c, n);
	res1 = ft_memchr(s, c, n);
	if (res0)
		TEST_ASSERT_EQUAL_MEMORY(res0, res1, n);
	else
		TEST_ASSERT_EQUAL_PTR(res0, res1);
}

void	test_memchr(void)
{
	helper_memchr("hola", 'h', 0);
	helper_memchr("hola", 'h', 1);
	helper_memchr("hola", 'z', 4);
	helper_memchr("hola", 'l', 4);
	helper_memchr("hola", 0, 4);
	helper_memchr("hola", 0, 5);
}
