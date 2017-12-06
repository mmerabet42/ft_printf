/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:12:58 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/06 21:45:13 by mmerabet         ###   ########.fr       */
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

char	*handler_p(va_list lst, t_printf_params params)
{
	char	*str;
	void	*ptr;

	ptr = va_arg(lst, void *);
	str = ft_ulltoa_cbase((unsigned long long)ptr, FT_HEX);
	str = padzero(str, &params);
	return (perform_width(ft_strjoin_clr("0x", str, 1), params));
}
