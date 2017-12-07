/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:12:58 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/07 21:44:23 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_p(va_list lst, t_printf_params params)
{
	char	*str;
	void	*ptr;

	ptr = va_arg(lst, void *);
	str = ft_ulltoa_cbase((unsigned long long)ptr, FT_HEX);
	params.width -= 2;
	str = pad_zeroes(str, &params);
	params.width += 2;
	return (perform_width(ft_strjoin_clr("0x", str, 1), params));
}
