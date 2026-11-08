#include "unity.h"

void	test_isalpha(void);
void	test_isdigit(void);
void	test_isalnum(void);
void	test_isascii(void);
void	test_isprint(void);
void    test_strlen(void);
void	test_memset(void);
void	test_bzero(void);
void	test_memcpy(void);
void	test_memmove(void);
void	test_strlcpy(void);
void	test_strlcat(void);
void	test_toupper(void);
void	test_tolower(void);
void	test_strchr(void);
void	test_strrchr(void);
void	test_strncmp(void);
void	test_memchr(void);
void	test_memcmp(void);
void	test_strnstr(void);
void	test_atoi(void);
void    test_calloc(void);
void    test_strdup(void);
void	test_substr(void);
void    test_strjoin(void);
void    test_strtrim(void);
void    test_split(void);
void	test_itoa(void);
void	test_strmapi(void);
void	test_striteri(void);
void	test_putchar(void);
void	test_putstr(void);
void	test_putendl(void);
void	test_putnbr(void);
void	test_lstnew(void);
void	test_lstadd_front(void);

void	setUp(void)
{
	return ;
}

void	tearDown(void)
{
	return ;
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_isalpha);
	RUN_TEST(test_isdigit);
	RUN_TEST(test_isalnum);
	RUN_TEST(test_isascii);
	RUN_TEST(test_isprint);
	RUN_TEST(test_strlen);
	RUN_TEST(test_memset);
	RUN_TEST(test_bzero);
	RUN_TEST(test_memcpy);
	RUN_TEST(test_memmove);
	RUN_TEST(test_strlcpy);
	RUN_TEST(test_strlcat);
	RUN_TEST(test_toupper);
	RUN_TEST(test_tolower);
	RUN_TEST(test_strchr);
	RUN_TEST(test_strrchr);
	RUN_TEST(test_strncmp);
	RUN_TEST(test_memchr);
	RUN_TEST(test_memcmp);
	RUN_TEST(test_strnstr);
	RUN_TEST(test_atoi);
	RUN_TEST(test_calloc);
	RUN_TEST(test_strdup);
	RUN_TEST(test_substr);
	RUN_TEST(test_strjoin);
	RUN_TEST(test_strtrim);
	RUN_TEST(test_split);
	RUN_TEST(test_itoa);
	RUN_TEST(test_strmapi);
	RUN_TEST(test_striteri);
	RUN_TEST(test_putchar);
	RUN_TEST(test_putstr);
	RUN_TEST(test_putendl);
	RUN_TEST(test_putnbr);
	RUN_TEST(test_lstnew);
	RUN_TEST(test_lstadd_front);
	return (UNITY_END());
}
