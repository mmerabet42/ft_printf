/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:58:14 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/13 22:54:28 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static t_list			*g_printf_formats = NULL;
static t_list			*g_printf_last = NULL;

static int		formatcmp(const void *a, const void *b, size_t n)
{
	t_printf_format	*fa;
	t_printf_format *fb;

	(void)n;
	fa = (t_printf_format *)a;
	fb = (t_printf_format *)b;
	return (ft_strncmp(fa->format, fb->format, ft_strlen(fa->format)));
}

char			*ft_handle_format(va_list lst,
							const char **format,
							t_printf_params params)
{
	t_printf_format	tmp;
	t_list			*t;

	tmp.format = (char *)*format;
	t = ft_lstfindf(g_printf_formats, &tmp, sizeof(t_printf_format), formatcmp);
	if (t)
	{
		tmp = *(t_printf_format *)t->content;
		*format += ft_strlen(tmp.format);
		params.format = format;
		if (tmp.printfunc)
			return (tmp.printfunc(lst, params));
	}
	return (perform_width(ft_strcatc(ft_strnew(1), *(*format)++), &params));
}

int				ft_printf_add_format(const char *f, t_printfunc func)
{
	t_printf_format	format;
	t_list			*tmp;
	size_t			szfmt;

	szfmt = sizeof(t_printf_format);
	format.format = (char *)f;
	format.printfunc = func;
	if (!ft_lstfindf(g_printf_formats, &format, szfmt, formatcmp))
	{
		tmp = ft_lstnew(&format, szfmt);
		if (g_printf_last == NULL)
			g_printf_formats = tmp;
		else
			g_printf_last->next = tmp;
		g_printf_last = tmp;
		return (1);
	}
	return (0);
}

void			ft_printf_add_basic_formats(void)
{
	static int	frst_call;

	if (!frst_call)
	{
		frst_call = 1;
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
		ft_printf_add_format("{", handler_color);
	}
}

void			ft_printf_free_formats(void)
{
	ft_lstdel(&g_printf_formats, NULL);
}
