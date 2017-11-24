#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef void (*t_printfunc)(va_list);

typedef struct	s_printf_format
{
	char		*format;
	t_printfunc	printfunc;
}				t_printf_format;

void	ft_printf(const char *format, ...);
int		ft_printf_add_format(const char *f, t_printfunc func);

#endif
