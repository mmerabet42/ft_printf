/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:48:07 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/11 15:04:18 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_b(va_list lst, t_printf_params params)
{
	char				*str;

	str = ft_ulltoa_cbase(proper_cast_u(lst, params), FT_BIN);
	return (perform_width(pad_zeroes(str, &params), &params));
}
