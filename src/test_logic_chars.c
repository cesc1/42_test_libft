#include "unity.h"
#include "libft.h"
#include <ctype.h>

void	test_isalpha(void)
{
	int	i;

	i = -1;
	while (++i < 256)
	{
		TEST_ASSERT_TRUE((isalpha(i) > 0) == (ft_isalpha(i) > 0));
	}
}

void	test_isdigit(void)
{
	int	i;

	i = -1;
	while (++i < 256)
	{
		TEST_ASSERT_TRUE((isdigit(i) > 0) == (ft_isdigit(i) > 0));
	}
}

void	test_isalnum(void)
{
	int	i;

	i = -1;
	while (++i < 256)
	{
		TEST_ASSERT_TRUE((isalnum(i) > 0) == (ft_isalnum(i) > 0));
	}
}

void	test_isascii(void)
{
	int	i;

	i = -1;
	while (++i < 256)
	{
		TEST_ASSERT_TRUE((isascii(i) > 0) == (ft_isascii(i) > 0));
	}
}

void	test_isprint(void)
{
	int	i;

	i = -1;
	while (++i < 256)
	{
		TEST_ASSERT_TRUE((isprint(i) > 0) == (ft_isprint(i) > 0));
	}
}
