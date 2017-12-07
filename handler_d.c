/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:26:52 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/07 19:24:31 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include <stdio.h>
static char	*handler_flag(char *s, int n, int l, t_printf_params params)
{
	char	adder;

	adder = 0;
	if (n < 0)
		adder = '-';
	else if (params.flags[PLUS_FLAG] && n >= 0)
		adder = '+';
	else if (params.flags[SPACE_FLAG] && n >= 0)
		adder = ' ';
	if (n < 0 || params.flags[PLUS_FLAG] || params.flags[SPACE_FLAG])
		params.width -= 1;
	s = pad_zeroes(s, &params);
	if (adder && ((n < 0 && params.precision >= l) || n >= 0))
		s = ft_strjoincs_clr(adder, s);
	s = perform_width(s, params);
	if (params.flags[ZERO_FLAG] && adder)
	{
		*ft_strchr(s, adder) = '0';
		s[0] = adder;
	}
	return (s);
}

char		*handler_d(va_list lst, t_printf_params params)
{
	long long	n;
	int			len;
	char		*str;

	n = proper_cast((long long)va_arg(lst, long long), params);
	str = ft_lltoa(n);
	len = ft_strlen(str);
	if (n < 0 && len <= params.precision)
		str[0] = '0';
	return (handler_flag(str, n, len, params));
}

char		*handler_d_m(va_list lst, t_printf_params params)
{
	params.flags[LL_MOD] = 0;
	params.flags[L_MOD] = 1;
	return (handler_d(lst, params));
}
