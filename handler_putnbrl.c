/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putnbrl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:48:56 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/03 22:05:47 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_handlers.h"

static char	*handler_putnbr_flag(char *s, long n, int l, t_printf_params params)
{
	char	adder;

	adder = 0;
	if (params.flags[SPACE_FLAG] && n >= 0)
		adder = ' ';
	if (params.flags[PLUS_FLAG] && n >= 0)
		adder = '+';
	if (n < 0)
		adder = '-';
	if (adder && ((n < 0 && l > 0) || n >= 0))
		s = ft_strjoincs_clr(adder, s);
	s = perform_width(s, params);
	if (params.flags[ZERO_FLAG] && adder)
	{
		*ft_strchr(s, adder) = '0';
		s[0] = adder;
	}
	return (s);
}

char		*handler_putnbrl(va_list lst, t_printf_params params)
{
	long	nbr;
	int		len;
	char	*str;

	nbr = va_arg(lst, long);
	len = ft_longlen(nbr);
	len = (params.precision > len ? params.precision - len : 0);
	str = ft_ltoa(nbr);
	if (len > 0)
		str = ft_strjoin_clr(ft_memset(ft_strnew(len), '0', len), str, 2);
	if (nbr < 0 && len > 0)
		*ft_strchr(str, '-') = '0';
	if (params.precision && params.flags[ZERO_FLAG])
		params.flags[ZERO_FLAG] = 0;
	return (handler_putnbr_flag(str, nbr, len, params));
}
