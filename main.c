#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wctype.h>
#include <fcntl.h>

#define PRINTFT "Hello"

int main(int argc, char **argv)
{

	ft_printf("%*{%s}%#{%s}TEST\n", ft_atoi(argv[1]), argv[2], argv[3]);

	return (0);
	/*int	i = 16;

	while (i <= 21)
		ft_printf("%0#{%d}Hello%{0}%#{green}|", i++);
	while (i > 16)
		ft_printf("%0#{%d}Hello%{0}%#{green}|", --i);
	return (0);
	char *lol = ft_strnew(0);
	ft_printf("BEFORE %0{%s}%0{%s}'Hello'%-{} AFTER\n", argv[1], argv[2]);

	return (0);*/
	/*int fd = open("FILETEST", O_RDWR);
	ft_printf_fd(fd, "%s%c%s", "Hello", '\n', "world");
	return (0);
	char *str = ft_ulltoa_cbase(789, "0123456789abcdef");
	free(str);
	str = "Hello ok";
	free(str);
	//printf("l: '%s'\n", str);
	return (0);
	printf("4567 |%-10]5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("|% 010+ d|\n", 12);
	printf("|%-10=|\n", 12);:wq
	printf("|%010.5d|\n", -12);
	printf("|%10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);*/
	//setlocale(LC_ALL, "");
	ft_printf("FT_PRINTF: \n'");
	int ftlen = ft_printf(PRINTFT);
	printf("'\nPRINTF: \n'");
	int len = printf(PRINTFT);

	printf("'\nmy : %d - his : %d\n", ftlen, len);
	return (0);
}
