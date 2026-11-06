#include "unity.h"
#include "libft.h"
#include <string.h>

static void	test_helper(void *(*f_orig)(void *, const void *, size_t),
						void *(*f_libft)(void *, const void *, size_t),
						const void *src, size_t n)
{
	char	str0[] = "123456789";
    char	str1[] = "123456789";
	char	*res0;
	char	*res1;

	res0 = f_orig(str0, src, n);
	res1 = f_libft(str1, src, n);
	TEST_ASSERT_EQUAL_MEMORY(res0, res1, 9);
	TEST_ASSERT_EQUAL_MEMORY(str0, str1, 9);
}

void	test_memcpy(void)
{
	test_helper(memcpy, ft_memcpy, "", 0);
	test_helper(memcpy, ft_memcpy, "", 1);
	test_helper(memcpy, ft_memcpy, "a", 1);
	test_helper(memcpy, ft_memcpy, "a", 2);
	test_helper(memcpy, ft_memcpy, "hola que pasa neeen", 7);
}

void	test_memmove(void)
{
	char	str0[] = "123456789";
    char	str1[] = "123456789";

	test_helper(memmove, ft_memmove, "", 0);
	test_helper(memmove, ft_memmove, "", 1);
	test_helper(memmove, ft_memmove, "a", 0);
	test_helper(memmove, ft_memmove, "a", 1);
	test_helper(memmove, ft_memmove, "a", 2);
	test_helper(memmove, ft_memmove, "hola que pasa neeen", 7);
	test_helper(memmove, ft_memmove, "hola que.", 9);
	(void)memmove(str0 + 2, str0, 5);
	(void)ft_memmove(str1 + 2, str1, 5);
	TEST_ASSERT_EQUAL_MEMORY(str0, str1, 9);
}
