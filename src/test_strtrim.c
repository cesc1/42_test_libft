#include "unity.h"
#include "libft.h"
#include <stdlib.h>

static void	helper_strtrim(char const *s1, char const *set, char *expected)
{
	char	*result;

	result = ft_strtrim(s1, set);
	if (!result)
		return ;
	TEST_ASSERT_EQUAL_STRING(result, expected);
	free(result);
}

void	test_strtrim(void)
{
	// empty
	helper_strtrim("", "", "");
	// empty s1
	helper_strtrim("", " .", "");
	// empty set
	helper_strtrim(".abc ", "", ".abc ");
	// Standard
	helper_strtrim(" .  .hola", " .", "hola");
	helper_strtrim("hola .  ..", " .", "hola");
	helper_strtrim(".....hola .  ..", " .", "hola");
	// Full set s1
	helper_strtrim(". . .  .", " .", "");
}
