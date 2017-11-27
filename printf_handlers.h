#ifndef PRINTF_HANDLERS_H
# define PRINTF_HANDLERS_H

#include "ft_printf.h"

void handler_putstr(va_list lst);
void handler_putnbr(va_list lst);
void handler_putptr(va_list lst);

#endif
