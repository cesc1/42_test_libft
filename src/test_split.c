#include "unity.h"
#include "libft.h"
#include <stdlib.h>

void	helper_split(char const *s, char c, char **expected)
{
	char	**result;
	int		i;

	result = ft_split(s, c);
	if (!result)
		return ;
	i = -1;
	while (expected[++i])
	{
		TEST_ASSERT_EQUAL_STRING(expected[i], result[i]);
		free(result[i]);
	}
	TEST_ASSERT_EQUAL_STRING(NULL, result[i]);
	free(result);
}

void	test_split(void)
{
	char	*res0[] = {NULL};
	char	*res1[] = {"Hola", NULL};
	char	*res2[] = {"Hola", "que", "tal", NULL};

	// Null char
	helper_split("Hola", '\0', res1);
	// Null string
	helper_split("", ' ', res0);
	helper_split("........", '.', res0);
	// No find char
	helper_split("Hola", 'z', res1);
	// Normal test
	helper_split("Hola que tal", ' ', res2);
	helper_split("  Hola que tal", ' ', res2);
	helper_split("Hola que tal    ", ' ', res2);
	helper_split("Hola   que    tal    ", ' ', res2);
	// Only 1 split with ending starting char
	helper_split(" Hola ", ' ', res1);
	helper_split("        Hola       ", ' ', res1);
}
