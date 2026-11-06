#include "unity.h"
#include "libft.h"
#include <bsd/string.h>

static void	helper_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*res_orig;
	char	*res_mine;

	res_orig = strnstr(s1, s2, n);
	res_mine = ft_strnstr(s1, s2, n);
    if (res_orig && res_mine)
        TEST_ASSERT_EQUAL_STRING(res_orig, res_mine);
    else
        TEST_ASSERT_EQUAL_PTR(res_orig, res_mine);
}

void	test_strnstr(void)
{
	// 0
	helper_strnstr("", "", 0);
	helper_strnstr("hola", "hola", 0);
	helper_strnstr("a", "b", 0);
	// Little empty
	helper_strnstr("", "", 5);
	helper_strnstr("hola", "", 5);
	// Same size
	helper_strnstr("hola", "hola", 3);
	helper_strnstr("hola", "hola", 4);
	helper_strnstr("hola", "hola", 5);
	helper_strnstr("hola", "holo", 3);
	helper_strnstr("hola", "holo", 4);
	helper_strnstr("hola", "holo", 5);
	// Diferent size, increase n
	helper_strnstr("0123456789", "234", 4);
	helper_strnstr("0123456789", "234", 5);
	helper_strnstr("0123456789", "234", 6);
	// Diferent size, increase little
	helper_strnstr("012", "01", 10);
	helper_strnstr("012", "012", 10);
	helper_strnstr("012", "0123", 10);
	// End of the string
	helper_strnstr("0123456789", "789", 9);
	helper_strnstr("0123456789", "789", 10);
	helper_strnstr("0123456789", "789", 11);
	helper_strnstr("0123456789", "789", 12);
}
