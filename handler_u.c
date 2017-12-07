/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putunbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:24:32 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/07 18:07:37 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_u(va_list lst, t_printf_params params)
{
	unsigned long long	n;
	char				*str;

	n = (unsigned long long)va_arg(lst, unsigned long long);
	n = proper_cast_u(n, params);
	str = pad_zeroes(ft_ulltoa(n), &params);
	if (params.flags[PLUS_FLAG])
		str = ft_strjoincs_clr('+', str);
	else if (params.flags[SPACE_FLAG])
		str = ft_strjoincs_clr('-', str);
	return (perform_width(str, params));
}

char		*handler_u_m(va_list lst, t_printf_params params)
{
	params.flags[LL_MOD] = 0;
	params.flags[L_MOD] = 1;
	return (handler_u(lst, params));
}
