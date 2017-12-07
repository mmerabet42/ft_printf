/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putunbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:24:32 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/07 21:32:32 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_u(va_list lst, t_printf_params params)
{
	unsigned long long	n;

	n = proper_cast_u(lst, params);
	return (perform_width(pad_zeroes(ft_ulltoa(n), &params), params));
}

char		*handler_u_m(va_list lst, t_printf_params params)
{
	params.flags[LL_MOD] = 0;
	params.flags[L_MOD] = 1;
	return (handler_u(lst, params));
}
