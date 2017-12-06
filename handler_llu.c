/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putunbrll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:41:22 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/04 22:18:40 by mmerabet         ###   ########.fr       */
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

char		*handler_llu(va_list lst, t_printf_params params)
{
	unsigned long long	nbr;
	char				*str;

	nbr = va_arg(lst, unsigned long long);
	str = padzero(ft_ulltoa(nbr), &params);
	if (params.flags[PLUS_FLAG])
		str = ft_strjoincs_clr('+', str);
	else if (params.flags[SPACE_FLAG])
		str = ft_strjoincs_clr('-', str);
	return (perform_width(str, params));
}
