/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putunbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:24:32 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/06 21:37:24 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include <stdio.h>
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
	zeroes = (zeroes < 0 ? 0 : zeroes);
	zstr = (char *)ft_memset(ft_strnew(zeroes), '0', zeroes);
	return (ft_strjoin_clr(zstr, str, 2));
}

char	*handler_u(va_list lst, t_printf_params params)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(lst, unsigned int);
	str = padzero(ft_uitoa(nbr), &params);
	if (params.flags[PLUS_FLAG])
		str = ft_strjoincs_clr('+', str);
	else if (params.flags[SPACE_FLAG])
		str = ft_strjoincs_clr('-', str);
	return (perform_width(str, params));
}
