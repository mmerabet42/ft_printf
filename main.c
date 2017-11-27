#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	printf("4567 |%-10]5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("|%#010x|\n", 12);
	printf("|%10d|\n", 12);
	printf("|%010.5d|\n", -12); 
	printf("|%10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);
	return (0);
}
