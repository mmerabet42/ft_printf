/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:55:47 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/07 18:51:07 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_o(va_list lst, t_printf_params params)
{
	char				*str;
	unsigned long long	n;

	n = (unsigned long long)va_arg(lst, unsigned long long);
	n = proper_cast_u(n, params);
	if (params.precision_spec && params.precision == 0 && n == 0)
	{
		if (params.flags[HASH_FLAG])
			str = ft_strdup("0");
		else
			str = ft_strdup("");
	}
	else
		str = ft_ulltoa_cbase(n, FT_OCT);
	if (params.flags[HASH_FLAG] && n != 0)
		params.width -= 2;
	str = pad_zeroes(str, &params);
	if (params.flags[HASH_FLAG] && n != 0)
	{
		str = ft_strjoin_clr("0", str, 1);
		params.width += 2;
	}
	str = perform_width(str, params);
	return (str);
}

char	*handler_o_m(va_list lst, t_printf_params params)
{
	params.flags[LL_MOD] = 0;
	params.flags[L_MOD] = 1;
	return (handler_o(lst, params));
}
