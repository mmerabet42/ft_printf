/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putunbrl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:36:19 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/03 22:36:32 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_handlers.h"

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

char	*handler_putunbr(va_list lst, t_printf_params params)
{
	unsigned long	nbr;
	char			*str;

	nbr = va_arg(lst, unsigned long);
	str = ft_uitoa(nbr);
	str = padzero(str, &params);
	if (params.flags[PLUS_FLAG])
		str = ft_strjoincs_clr('+', str);
	else if (params.flags[SPACE_FLAG])
		str = ft_strjoincs_clr('-', str);
	return (perform_width(str, params));
}
