#include "ft_printf.h"
#include "printf_handlers.h"

static char	*handler_putnbr_flag(int n, int len, t_printf_params params)
{
	if (params.flags[PLUS_FLAG] && n >= 0)
		ft_putchar('+');
	else if (params.flags[SPACE_FLAG] && n >= 0)
		ft_putchar(' ');
	else if (n < 0)
		ft_putchar('-');
	ft_putnchar('0', len);
	ft_putnbr(n < 0 ? -n : n);
	return (NULL);
}

char	*handler_putnbr(va_list lst, t_printf_params params)
{
	int	nbr;
	int	len;
	int	nblen;

	nbr = va_arg(lst, int);
	nblen = ft_intlen(nbr) - (nbr < 0 ? 1 : 0);
	nblen = params.precision - nblen;
	nblen = (nblen < 0 ? 0 : nblen);
	len = params.width - nblen - ft_intlen(nbr) - (nbr >= 0 && (params.flags[PLUS_FLAG] || params.flags[SPACE_FLAG]));
	if (params.flags[MINUS_FLAG])
		handler_putnbr_flag(nbr, nblen, params);
	ft_putnchar((params.flags[ZERO_FLAG] && !params.flags[MINUS_FLAG] ? '0' : ' '), len < 0 ? 0 : len);
	if (!params.flags[MINUS_FLAG])
		handler_putnbr_flag(nbr, nblen, params);
	return (NULL);
}
