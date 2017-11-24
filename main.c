#include "ft_printf.h"
#include <stdio.h>

void ft_printf_putstr(va_list lst)
{
	char	*s = va_arg(lst, char *);
	ft_putstr(s);
}

void ft_printf_putnbr(va_list lst)
{
	ft_putnbr(va_arg(lst, int));
}

void ft_printf_putptr(va_list lst)
{
	ft_putptr(va_arg(lst, void *));
}

typedef struct s_struct
{
	int a;
	char *b;
} t_struct;

void ft_printf_putstruct(va_list lst)
{
	t_struct a = va_arg(lst, t_struct);
	ft_printf("{%d, '%s'}", a.a, a.b);
}

int main()
{
	ft_printf_add_format("s", ft_printf_putstr);
	ft_printf_add_format("d", ft_printf_putnbr);
	ft_printf_add_format("p", ft_printf_putptr);
	ft_printf_add_format("yu", ft_printf_putstruct);
	t_struct a;
	a.a = 5;
	a.b = "Hello";
	ft_printf("%s%yu%s\n%.5rc", "BEGIN", a, "END");
	return (0);
}
