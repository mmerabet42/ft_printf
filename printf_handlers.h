#ifndef PRINTF_HANDLERS_H
# define PRINTF_HANDLERS_H

#include "ft_printf.h"

char	*replace_width(char *str, t_printf_params params);
char	*handler_putstr(va_list lst, t_printf_params params);
char	*handler_putnbr(va_list lst, t_printf_params params);
char	*handler_putptr(va_list lst, t_printf_params params);

#endif
