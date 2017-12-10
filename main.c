#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

#define PRINTFT "s:%s C:%c d:%d p:%p x:%x %%:%% S:%s\n", "bonjour ", 'l', 42, &free, 42, "Hello"

int main()
{
	/*char *str = ft_ulltoa_cbase(789, "0123456789abcdef");
	free(str);
	str = "Hello ok";
	free(str);
	//printf("l: '%s'\n", str);
	return (0);
	/*printf("4567 |%-10]5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("|% 010+ d|\n", 12);
	printf("|%-10=|\n", 12);
	printf("|%010.5d|\n", -12);
	printf("|%10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);*/
	char *frmt = "'%.*f'\n";
	double t = 42;
	int ftlen = ft_printf(frmt, 0, t);
	int len = printf(frmt, 0, t);

	printf("my : %d - his : %d\n", ftlen, len);
	return (0);
}
