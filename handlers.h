#ifndef HANDLERS_H
# define HANDLERS_H

#include "ft_printf.h"

char	*perform_width(char *str, t_printf_params params);

char	*handler_s(va_list lst, t_printf_params params);
char	*handler_d(va_list lst, t_printf_params params);
char	*handler_ld(va_list lst, t_printf_params params);
char	*handler_lld(va_list lst, t_printf_params params);
char	*handler_u(va_list lst, t_printf_params params);
char	*handler_lu(va_list lst, t_printf_params params);
char	*handler_llu(va_list lst, t_printf_params params);
char	*handler_p(va_list lst, t_printf_params params);

#endif
