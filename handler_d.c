/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:26:52 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/06 22:45:58 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static char *padzero(char *str, t_printf_params *params)
{
	int		len;
	int		zeroes;
	char	*zstr;

	len = ft_strlen(str);
	zeroes = 0;
	if (params->precision_spec)
	{
		params->flags[ZERO_FLAG] = 0;
		zeroes = params->precision - len;
	}
	else if (params->flags[ZERO_FLAG])
		zeroes = params->width - 2 - len;
	zeroes = (zeroes < 0 ? 0 : zeroes);
	zstr = (char *)ft_memset(ft_memalloc(zeroes + 1), '0', zeroes);
	return (ft_strjoin_clr(zstr, str, 2));
}

static char	*handler_flag(char *s, int n, int l, t_printf_params params)
{
	char	adder;

	adder = 0;
	if (params.flags[SPACE_FLAG] && n >= 0)
		adder = ' ';
	if (params.flags[PLUS_FLAG] && n >= 0)
		adder = '+';
	if (n < 0)
		adder = '-';
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
#include <stdio.h>
char		*handler_d(va_list lst, t_printf_params params)
{
	int		nbr;
	int		len;
	char	*str;

	printf("ll : %d\n", params.flags[LL_MOD]);
	printf("l : %d\n", params.flags[L_MOD]);
	printf("hh : %d\n", params.flags[HH_MOD]);
	printf("h : %d\n", params.flags[H_MOD]);
	printf("j : %d\n", params.flags[J_MOD]);
	printf("z : %d\n", params.flags[Z_MOD]);
	nbr = va_arg(lst, int);
	str = ft_itoa(nbr);
	len = ft_strlen(str);
	if (nbr < 0 && len <= params.precision)
		str[0] = '0';
	return (handler_flag(padzero(str, &params), nbr, len, params));
}
