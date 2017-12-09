/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 20:18:28 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/09 23:20:53 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include <stdio.h>

char	*handler_p(va_list lst, t_printf_params params)
{
	char	*str;
	void	*ptr;

	ptr = va_arg(lst, void *);
	str = ft_ulltoa_cbase((unsigned long long)ptr, FT_HEX);
	params.width -= 2;
	str = pad_zeroes(str, &params);
	params.width += 2;
	str = ft_strjoin_clr("0x", str, 1);
	printf("HELLO : '%s'\n", str);
	return (perform_width(str, params));
}
