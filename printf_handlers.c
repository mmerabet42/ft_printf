#include "ft_printf.h"

void handler_putstr(va_list lst)
{
	ft_putstr(va_arg(lst, char *));
}

void handler_putnbr(va_list lst)
{
	ft_putnbr(va_arg(lst, int));
}

void handler_putptr(va_list lst)
{
	ft_putptr(va_arg(lst, void *));
}
