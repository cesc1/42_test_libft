#include "unity.h"
#include "libft.h"
#include <bsd/string.h>
#include <stddef.h>

static void	test_helper(size_t (*f_orig)(char *dst, const char *src, size_t size),
					size_t (*f_libft)(char *dst, const char *src, size_t size),
					const char *src, size_t size)
{
	char	dst0[100] = {'0'};
	char	dst1[100] = {'0'};
	size_t	res0;
	size_t	res1;

	res0 = f_orig(dst0, src, size);
	res1 = f_libft(dst1, src, size);
	TEST_ASSERT_EQUAL_MEMORY(dst0, dst1, 100);
	TEST_ASSERT_EQUAL(res0, res1);
}

void	test_strlcpy(void)
{
	test_helper(strlcpy, ft_strlcpy, "", 0);
	test_helper(strlcpy, ft_strlcpy, "", 5);
	test_helper(strlcpy, ft_strlcpy, "hola", 0);
	test_helper(strlcpy, ft_strlcpy, "hola", 1);
	test_helper(strlcpy, ft_strlcpy, "hola", 2);
	test_helper(strlcpy, ft_strlcpy, "hola", 3);
	test_helper(strlcpy, ft_strlcpy, "hola", 4);
	test_helper(strlcpy, ft_strlcpy, "hola", 5);
	test_helper(strlcpy, ft_strlcpy, "hola", 6);
	test_helper(strlcpy, ft_strlcpy, "hola", 7);
}
