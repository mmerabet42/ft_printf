#ifndef PRINTF_HANDLERS_H
# define PRINTF_HANDLERS_H

#include "ft_printf.h"

void handler_putstr(va_list lst, t_printf_params params);
void handler_putnbr(va_list lst, t_printf_params params);
void handler_putptr(va_list lst, t_printf_params params);

#endif
