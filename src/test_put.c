#include "unity.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	assert_file_content(char *filename, char *expected)
{
	size_t	n;
	int		fd;
	char	*buffer;
	ssize_t	bytes_read;


	fd = open(filename, O_RDONLY);
	TEST_ASSERT_TRUE_MESSAGE(fd >= 0, "Could not open file");
	n = ft_strlen(expected);
	buffer = (char *)malloc(n);
	TEST_ASSERT_NOT_NULL(buffer);
	bytes_read = read(fd, buffer, n + 1);
	TEST_ASSERT_EQUAL_INT(n, bytes_read);
	TEST_ASSERT_EQUAL_MEMORY(expected, buffer, n);
	close(fd);
	free(buffer);
	unlink(filename);
}

static int	create_file(char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	TEST_ASSERT_TRUE_MESSAGE(fd >= 0, "Could not open file");
	return (fd);
}

static void helper_putchar(char c, char *expected, char *filename)
{
	int	fd;

	fd = create_file(filename);
	ft_putchar_fd(c, fd);
	close(fd);
	assert_file_content(filename, expected);
}

static void helper_putstr(char *str, char *expected, char *filename)
{
	int	fd;

	fd = create_file(filename);
	ft_putstr_fd(str, fd);
	close(fd);
	assert_file_content(filename, expected);
}

static void helper_putendl(char *str, char *expected, char *filename)
{
	int	fd;

	fd = create_file(filename);
	ft_putendl_fd(str, fd);
	close(fd);
	assert_file_content(filename, expected);
}

static void helper_putnbr(int num, char *expected, char *filename)
{
	int	fd;

	fd = create_file(filename);
	ft_putnbr_fd(num, fd);
	close(fd);
	assert_file_content(filename, expected);
}

void	test_putchar(void)
{
	char	*filename = "obj/tmp_file.txt";

	helper_putchar('H', "H", filename);
	helper_putchar('\n', "\n", filename);
}

void	test_putstr(void)
{
	char	*filename = "obj/tmp_file.txt";

	helper_putstr("Hola que tal", "Hola que tal", filename);
}

void	test_putendl(void)
{
	char	*filename = "obj/tmp_file.txt";

	helper_putendl("", "\n", filename);
	helper_putendl("Hola", "Hola\n", filename);
	helper_putendl("Hola\n", "Hola\n\n", filename);
}

void	test_putnbr(void)
{
	char	*filename = "obj/tmp_file.txt";

	helper_putnbr(0, "0", filename);
	helper_putnbr(-5, "-5", filename);
	helper_putnbr(5, "5", filename);
	helper_putnbr(-123, "-123", filename);
	helper_putnbr(123, "123", filename);
	helper_putnbr(2147483647, "2147483647", filename);
	helper_putnbr(-2147483648, "-2147483648", filename);
}
