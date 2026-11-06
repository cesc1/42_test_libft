#include "unity.h"
#include "libft.h"
#include <string.h>

static void	helper_memcmp(const void *s1, const void *s2, size_t n)
{
	int	res_orig;
	int	res_mine;

	res_orig = memcmp(s1, s2, n);
	res_mine = ft_memcmp(s1, s2, n);
	TEST_ASSERT_TRUE((res_orig > 0) == (res_mine > 0));
	TEST_ASSERT_TRUE((res_orig == 0) == (res_mine == 0));
	TEST_ASSERT_TRUE((res_orig < 0) == (res_mine < 0));
}

void	test_memcmp(void)
{
	// 0
	helper_memcmp("", "", 0);
	helper_memcmp("hola", "hola", 0);
	helper_memcmp("a", "b", 0);
	// Same size
	helper_memcmp("hola", "hola", 3);
	helper_memcmp("hola", "hola", 4);
	helper_memcmp("hola", "hola", 5);
	helper_memcmp("hola", "holo", 3);
	helper_memcmp("hola", "holo", 4);
	helper_memcmp("hola", "holo", 5);
	// Diferent size
	helper_memcmp("0123456789", "123", 2);
	helper_memcmp("0123456789", "123", 3);
	helper_memcmp("0123456789", "123", 4);
	helper_memcmp("012", "0123456789", 2);
	helper_memcmp("012", "0123456789", 3);
	helper_memcmp("012", "0123456789", 4);
	// Diferent size diferent str
	helper_memcmp("012", "012456789", 2);
	helper_memcmp("012", "012456789", 3);
	helper_memcmp("012", "012456789", 4);
	helper_memcmp("0123", "012456789", 2);
	helper_memcmp("0123", "012456789", 3);
	helper_memcmp("0123", "012456789", 4);
	helper_memcmp("0123", "012456789", 5);
}

