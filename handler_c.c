/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:30:13 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/11 19:34:06 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include <wctype.h>

char	*handler_c(va_list lst, t_printf_params params)
{
	char	*str;
	char	c;

	c = (char)va_arg(lst, int);
	str = ft_strnew(1);
	str[0] = (c == 0 ? -1 : c);
	return (perform_width(str, &params));
}

char	*handler_c_m(va_list lst, t_printf_params params)
{
	char	*str;
	wchar_t	c;

	c = (wchar_t)va_arg(lst, wchar_t);
	if (c == 0)
	{
		str = ft_strnew(1);
		str[0] = -1;
	}
	else
		str = ft_getwchar(c);
	return (perform_width(str, &params));
}

