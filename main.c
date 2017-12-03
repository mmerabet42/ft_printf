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
	char *frmt = "'%0#200.8u'\n";
	unsigned int t = UINT_MAX;
int ftlen = ft_printf(frmt, t);
	 int len = printf(frmt, t);
	
	printf("my : %d - his : %d\n", ftlen, len);
	return (0);
}
