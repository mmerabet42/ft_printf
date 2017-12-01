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
	int	nlen;
	int	len;
	int	neg;
	char	*str;
	char	*pos;

	nbr = va_arg(lst, int);
	neg = (nbr < 0 ? 1 : 0);
	nlen = ft_intlen(nbr);
	len = params.precision - nlen;
	len = (len < 0 ? 0 : len);
	str = ft_itoa(nbr);
	if (len > 0)
		str = ft_strjoin_clr(ft_memset(ft_strnew(len),'0', len), str, 2);
	str = replace_width(str, params);
	if (neg && len > 0)
	{
		pos = ft_strchr(str, '-');
		*pos = '0';
	}
	return (str);
	return (handler_putnbr_flag(nbr, len, params));
}
