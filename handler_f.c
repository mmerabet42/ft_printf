/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:53:37 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/10 23:00:23 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static char	*handler_flag(char *s, double n, int l, t_printf_params params)
{
	char	adder;

	adder = 0;
	if (n < 0)
		adder = '-';
	else if (params->flags[PLUS_FLAG] && n >= 0)
		adder = '+';
	else if (params->flags[SPACE_FLAG] && n >= 0)
		adder = ' ';
	if (adder && adder != '-')
		--params->width;
	s = pad_zeroes(s, params);
	if (adder && adder != '-')
		++params->width;
	if (adder && ((n < 0 && params->precision >= l) || n >= 0))
		s = ft_strjoincs_clr(adder, s);
	s = perform_width(s, params);
	if (params->flags[ZERO_FLAG] && adder)
	{
		*ft_strchr(s, adder) = '0';
		s[0] = adder;
	}
	return (s);
}

char		*handler_d(va_list lst, t_printf_params params)
{
	double		n;
	int			len;
	char		*str;

	n = (double)va_arg(lst, double);
	str = ft_dtoa(n, 0);
	len = ft_strlen(str);
	if (n < 0 && len <= params->precision)
		str[0] = '0';
	return (handler_flag(str, n, len, params));
}
