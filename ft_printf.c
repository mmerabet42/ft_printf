#include "ft_printf.h"
#include <stdio.h>

static t_btree	*g_printf_formats = NULL;

static int formatcmp(const void *a, const void *b, size_t n)
{
	(void)n;
	t_printf_format	*fa = (t_printf_format *)a;
	t_printf_format	*fb = (t_printf_format *)b;
	return (ft_strncmp(fa->format, fb->format, ft_strlen(fa->format)));
}

void	ft_printf(const char *format, ...)
{
	va_list			args;
	t_btree			*bt;
	t_printf_format	*fmt;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == '%')
				ft_putchar('%');
			else
			{
				t_printf_format	tmp;
				tmp.format = (char *)format;
				bt = ft_btree_searchf(g_printf_formats, &tmp, sizeof(t_printf_format), formatcmp);
				if (bt)
				{
					fmt = (t_printf_format *)(bt->content);
					format += ft_strlen(fmt->format) - 1;
					if (fmt->printfunc)
						fmt->printfunc(args);
				}
			}
		}
		else
			ft_putchar(*format);
		++format;
	}
	va_end(args);
}

int		ft_printf_add_format(const char *f, t_printfunc func)
{
	t_printf_format	format;
	t_btree			*tmp;

	format.format = (char *)f;
	format.printfunc = func;
	if (ft_btree_searchf(g_printf_formats, &format, sizeof(t_printf_format), formatcmp) == NULL)
	{
		tmp = ft_btree_insertf(g_printf_formats, ft_btree_new(&format, sizeof(t_printf_format)), formatcmp);
		if (g_printf_formats == NULL)
			g_printf_formats = tmp;
		return (1);
	}
	return (0);
}
