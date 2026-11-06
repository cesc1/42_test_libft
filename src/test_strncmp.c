#include "unity.h"
#include "libft.h"
#include <string.h>

static void	helper_strncmp(const char *s1, const char *s2, size_t n)
{
	int	res_orig;
	int	res_mine;

	res_orig = strncmp(s1, s2, n);
	res_mine = ft_strncmp(s1, s2, n);
	TEST_ASSERT_TRUE((res_orig > 0) == (res_mine > 0));
	TEST_ASSERT_TRUE((res_orig == 0) == (res_mine == 0));
	TEST_ASSERT_TRUE((res_orig < 0) == (res_mine < 0));
}

void	test_strncmp(void)
{
	// 0
	helper_strncmp("", "", 0);
	helper_strncmp("hola", "hola", 0);
	helper_strncmp("a", "b", 0);
	// Same size
	helper_strncmp("hola", "hola", 3);
	helper_strncmp("hola", "hola", 4);
	helper_strncmp("hola", "hola", 5);
	helper_strncmp("hola", "holo", 3);
	helper_strncmp("hola", "holo", 4);
	helper_strncmp("hola", "holo", 5);
	// Diferent size
	helper_strncmp("0123456789", "012", 2);
	helper_strncmp("0123456789", "012", 3);
	helper_strncmp("0123456789", "012", 4);
	helper_strncmp("0123456789", "012", 5);
	helper_strncmp("012", "0123456789", 2);
	helper_strncmp("012", "0123456789", 3);
	helper_strncmp("012", "0123456789", 4);
	helper_strncmp("012", "0123456789", 5);
	// Diferent size diferent str
	helper_strncmp("012", "012456789", 2);
	helper_strncmp("012", "012456789", 3);
	helper_strncmp("012", "012456789", 4);
	helper_strncmp("012", "012456789", 5);
	helper_strncmp("0123", "012456789", 2);
	helper_strncmp("0123", "012456789", 3);
	helper_strncmp("0123", "012456789", 4);
	helper_strncmp("0123", "012456789", 5);
}
