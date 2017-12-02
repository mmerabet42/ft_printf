#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define PRINTF_TEST "'%             d'\n", 2

int main()
{
	/*printf("4567 |%-10]5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("|% 010+ d|\n", 12);
	printf("|%-10=|\n", 12);
	printf("|%010.5d|\n", -12);
	printf("|%10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);*/
int ftlen = ft_printf(PRINTF_TEST);
	 int len = printf(PRINTF_TEST);
	
	printf("my : %d - his : %d\n", ftlen, len);
	return (0);
}
