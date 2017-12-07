/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:10:30 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/07 18:53:14 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_x(va_list lst, t_printf_params params)
{
	char				*str;
	unsigned long long	n;

	n = (unsigned long long)va_arg(lst, unsigned long long);
	n = proper_cast_u(n, params);
	if (params.precision_spec && params.precision == 0 && n == 0)
		str = ft_strdup("");
	else
		str = ft_ulltoa_cbase(n, FT_HEX);
	if (params.flags[HASH_FLAG] && n != 0)
		params.width -= 2;
	str = pad_zeroes(str, &params);
	if (params.flags[HASH_FLAG] && n != 0)
	{
		str = ft_strjoin_clr("0x", str, 1);
		params.width += 2;
	}
	str = perform_width(str, params);
	return (str);
}

char	*handler_x_m(va_list lst, t_printf_params params)
{
	char				*str;
	unsigned long long	n;

	n = (unsigned long long)va_arg(lst, unsigned long long);
	n = proper_cast_u(n, params);
	str = ft_ulltoa_cbase(n, FT_HEXM);
	if (params.flags[HASH_FLAG] && n != 0)
		params.width -= 2;
	str = pad_zeroes(str, &params);
	if (params.flags[HASH_FLAG] && n != 0)
	{
		str = ft_strjoin_clr("0X", str, 1);
		params.width += 2;
	}
	str = perform_width(str, params);
	return (str);
}