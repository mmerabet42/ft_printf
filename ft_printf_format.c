/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:58:14 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/10 23:19:00 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static t_list	*g_printf_formats = NULL;
static t_list	*g_printf_last = NULL;

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
	char			*buffer;
	t_printf_format	tmp;
	t_list			*t;

	buffer = NULL;
	tmp.format = (char *)*format;
	t = ft_lstfindf(g_printf_formats, &tmp, sizeof(t_printf_format), formatcmp);
	if (t)
	{
		tmp = *(t_printf_format *)t->content;
		*format += ft_strlen(tmp.format);
		if (tmp.printfunc)
			buffer = tmp.printfunc(lst, params);
	}
	else
		buffer = perform_width(ft_strcatc(ft_strnew(1), *(*format)++), &params);
	return (buffer);
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

void			ft_printf_free_formats(void)
{
	ft_lstdel(&g_printf_formats, NULL);
}
