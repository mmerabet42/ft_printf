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
	char *frmt = "'%c'\n";
	char t = '\0';
int ftlen = ft_printf(frmt, t);
	 int len = printf(frmt, t);

	//printf("my : %d - his : %d\n", ftlen, len);
	return (0);
}
