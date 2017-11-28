#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

# define PLUS_FLAG 0
# define MINUS_FLAG 1
# define HASH_FLAG 2
# define ZERO_FLAG 3
# define SPACE_FLAG 4

typedef struct	s_printf_params
{
	char		*format;
	int			width;
	int			precision;
	int			flags[5];
}				t_printf_params;

typedef void (*t_printfunc)(va_list, t_printf_params);

typedef struct	s_printf_format
{
	char		*format;
	t_printfunc	printfunc;
}				t_printf_format;

int		ft_printf(const char *format, ...);
int		ft_printf_add_format(const char *f, t_printfunc func);
void	ft_printf_free_formats();

#endif
