#include "unity.h"
#include "libft.h"
#include <bsd/string.h>
#include <stddef.h>

static char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	test_helper(size_t (*f_orig)(char *dst, const char *src, size_t size),
					size_t (*f_libft)(char *dst, const char *src, size_t size),
					char *dst, const char *src, size_t size)
{
	char	dst0[100] = {0};
	char	dst1[100] = {0};
	size_t	res0;
	size_t	res1;

	ft_strcpy(dst0, dst);
	ft_strcpy(dst1, dst);
	res0 = f_orig(dst0, src, size);
	res1 = f_libft(dst1, src, size);
	TEST_ASSERT_EQUAL_MEMORY(dst0, dst1, 100);
	TEST_ASSERT_EQUAL(res0, res1);
}

void	test_strlcat(void)
{
	test_helper(strlcat, ft_strlcat, "", "", 0);
	test_helper(strlcat, ft_strlcat, "", "", 5);
	test_helper(strlcat, ft_strlcat, "", "tes", 3);
	test_helper(strlcat, ft_strlcat, "", "tes", 4);
	test_helper(strlcat, ft_strlcat, "", "tes", 5);
	test_helper(strlcat, ft_strlcat, "hola", "tes", 3);
	test_helper(strlcat, ft_strlcat, "hola", "tes", 4);
	test_helper(strlcat, ft_strlcat, "hola", "tes", 5);
	test_helper(strlcat, ft_strlcat, "hola", "tes", 6);
	test_helper(strlcat, ft_strlcat, "hola", "tes", 7);
	test_helper(strlcat, ft_strlcat, "hola", "tes", 8);
	test_helper(strlcat, ft_strlcat, "hola", "tes", 9);
	test_helper(strlcat, ft_strlcat, "hola", "", 9);
}
