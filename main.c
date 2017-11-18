#include "ft_printf.h"
#include <stdio.h>

void ft_printf_putstr(va_list *lst)
{
	char	*s = va_arg(*lst, char *);
	ft_putstr(s);
}

void ft_printf_putnbr(va_list *lst)
{
	ft_putnbr(va_arg(*lst, int));
}

void ft_printf_putptr(va_list *lst)
{
	ft_putptr(va_arg(*lst, void *));
}

int main()
{
	ft_printf_add_format("s", ft_printf_putstr);
	ft_printf_add_format("d", ft_printf_putnbr);
	ft_printf_add_format("p", ft_printf_putptr);
	int a = 78;
	ft_printf("%p\n", &a);
	printf("%p\n", &a);
	return (0);
}
