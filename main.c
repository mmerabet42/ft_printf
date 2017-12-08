#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define PRINTFT "{% %}"

int main()
{
	/*printf("4567 |%-10]5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("|% 010+ d|\n", 12);
	printf("|%-10=|\n", 12);
	printf("|%010.5d|\n", -12);
	printf("|%10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);*/
	char *frmt = "'%c' Hello lol\n";
	char t = -1;
int ftlen = ft_printf(PRINTFT);
	 int len = printf(PRINTFT);

	printf("my : %d - his : %d\n", ftlen, len);
	return (0);
}
