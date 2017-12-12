#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wctype.h>

#define PRINTFT "%f", 10.096001//, L'暖', L'ح'

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
	//setlocale(LC_ALL, "");
	ft_printf("\nFT_PRINTF: \n'");
	int ftlen = ft_printf(PRINTFT);
	printf("'\nPRINTF: \n'");
	int len = printf(PRINTFT);

	printf("'\nmy : %d - his : %d\n", ftlen, len);
	return (0);
}
