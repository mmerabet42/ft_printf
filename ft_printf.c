/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:27:32 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/12 22:36:07 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "handlers.h"

static void		ft_printf_add_basic_formats(void)
{
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
	ft_printf_add_format("f", handler_f);
	ft_printf_add_format("F", handler_f);
	ft_printf_add_format("b", handler_b);
	ft_printf_add_format("q", handler_q);
}

static int		write_buffer(char *buffer)
{
	int	len;

	len = ft_strlen(buffer);
	len = write(1, ft_strrepc(buffer, -1, 0), len);
	free(buffer);
	return (len);
}

static int		ft_inner_printf(const char *format, va_list args)
{
	char	*cs[3];

	cs[0] = NULL;
	cs[1] = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			if (!(cs[2] = ft_printf_parser(&format, args)))
			{
				write_buffer(cs[0]);
				free(cs[1]);
				return (-1);
			}
			cs[0] = ft_strjoin_clr(ft_strjoin_clr(cs[0], cs[1], 2), cs[2], 2);
			cs[1] = NULL;
		}
		else
			cs[1] = ft_strjoinc_clr(cs[1], *format++);
	}
	return (write_buffer(ft_strjoin_clr(cs[0], cs[1], 2)));
}

int				ft_printf(const char *format, ...)
{
	static int	frstcall = 0;
	int			len;
	va_list		args;

	if (frstcall == 0)
	{
		frstcall = 1;
		ft_printf_add_basic_formats();
	}
	va_start(args, format);
	len = ft_inner_printf(format, args);
	va_end(args);
	return (len);
}

int				
