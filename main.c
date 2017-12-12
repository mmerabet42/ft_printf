#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

#define PRINTFT "%c\n%lc\n%lc\n", 128, L'暖', L'ح'

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
	printf("|%-10=|\n", 12);:wq
	printf("|%010.5d|\n", -12);
	printf("|%10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);*/
	setlocale(LC_ALL, "");
	char *frmt = "'%.3C'\n";
	unsigned long long t = 50;
	printf("PRINTF: \n");
	int len = printf(PRINTFT);
	ft_printf("FT_PRINTF: \n");
	int ftlen = ft_printf(PRINTFT);

	printf("my : %d - his : %d\n", ftlen, len);
	return (0);
}
