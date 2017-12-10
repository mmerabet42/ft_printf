/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:27:32 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/10 23:16:40 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "handlers.h"

static int		ft_inner_printf(const char *format, va_list args)
{
	char	*tmp;
	int		len;
	int		tmplen;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tmp = ft_printf_parser(&format, args);
			tmplen = ft_strlen(tmp);
			if (tmp)
				len += write(1, ft_strrepc(tmp, -1, 0), tmplen);
			free(tmp);
		}
		else
			len += write(1, format++, 1);
	}
	return (len);
}

int				ft_printf(const char *format, ...)
{
	static int	frstcall = 0;
	int			len;
	va_list		args;

	if (frstcall == 0)
	{
		frstcall = 1;
		ft_printf_add_format("s", handler_s);
		ft_printf_add_format("S", handler_s_m);
		ft_printf_add_format("p", handler_p);
		ft_printf_add_format("d", handler_d);
		ft_printf_add_format("D", handler_d_m);
		ft_printf_add_format("i", handler_d);
		ft_printf_add_format("o", handler_o);
		ft_printf_add_format("O", handler_o_m);
		ft_printf_add_format("u", handler_u);
		ft_printf_add_format("U", handler_u_m);
		ft_printf_add_format("x", handler_x);
		ft_printf_add_format("X", handler_x_m);
		ft_printf_add_format("c", handler_c);
		ft_printf_add_format("C", handler_c_m);
	}
	va_start(args, format);
	len = ft_inner_printf(format, args);
	va_end(args);
	return (len);
}
