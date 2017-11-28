#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	/*printf("4567 |%-10]5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("|% 010+ d|\n", 12);
	printf("|%-10=|\n", 12);
	printf("|%010.5d|\n", -12);
	printf("|%10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);*/
 ft_printf("|%+.5 10d|\n", 45);
	printf("|%+.5 10d|\n", 45);
	return (0);
}
