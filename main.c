#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

#define PRINTFT "'%.4S'\n", L"我是一只猫。"

int main()
{
	ft_printf("'%x'\n'%llk'\n", 785, "mohammed", "abcdefghijklmnopqrstuvwxyz");
	return (0);
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
	setlocale(LC_ALL, "");
	char *frmt = "'%.3C'\n";
	unsigned long long t = 50;
	int ftlen = ft_printf(PRINTFT);
	int len = printf(PRINTFT);

	printf("my : %d - his : %d\n", ftlen, len);
	return (0);
}
