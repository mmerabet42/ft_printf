#include "ft_printf.h"
#include "printf_handlers.h"

char	*handler_putstr(va_list lst, t_printf_params params)
{
	char	*gs;
	int		slen;

	gs = va_arg(lst, char *);
	if (!gs)
		gs = "(null)";
	slen = ft_strlen(gs);
	slen = (params.precision_spec && params.precision < slen ? params.precision : slen);
	gs = ft_strndup(gs, slen);
	return (replace_width(gs, params));
}
