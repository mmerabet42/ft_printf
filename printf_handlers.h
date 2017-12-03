#ifndef PRINTF_HANDLERS_H
# define PRINTF_HANDLERS_H

#include "ft_printf.h"

char	*perform_width(char *str, t_printf_params params);

char	*handler_putstr(va_list lst, t_printf_params params);
char	*handler_putnbr(va_list lst, t_printf_params params);
char	*handler_putnbrl(va_list lst, t_printf_params params);
char	*handler_putnbrll(va_list lst, t_printf_params params);
char	*handler_putunbr(va_list lst, t_printf_params params);
char	*handler_putunbrl(va_list lst, t_printf_params params);
char	*handler_putunbrll(va_list lst, t_printf_params params);
char	*handler_putptr(va_list lst, t_printf_params params);

#endif
