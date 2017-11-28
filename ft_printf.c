#include "ft_printf.h"
#include "printf_handlers.h"

static t_btree	*g_printf_formats = NULL;

static int	formatcmp(const void *a, const void *b, size_t n)
{
	(void)n;
	t_printf_format	*fa = (t_printf_format *)a;
	t_printf_format	*fb = (t_printf_format *)b;
	return (ft_strncmp(fa->format, fb->format, ft_strlen(fa->format)));
}

static void	 ft_printf_parse(const char **format, va_list lst)
{
	char			*index;
	t_btree			*bt;
	t_printf_params	params;
	t_printf_format	tmp;


	index = (char *)(*format);
	ft_bzero(&params, sizeof(t_printf_params));
	while (*index)
	{
		if (*index == '#')
			params.flags[HASH_FLAG] = 1;
		else if (*index == '+')
			params.flags[PLUS_FLAG] = 1;
		else if (*index == '-')
			params.flags[MINUS_FLAG] = 1;
		else if (*index == '0')
			params.flags[ZERO_FLAG] = 1;
		else if (*index == ' ')
			params.flags[SPACE_FLAG] = 1;
		else if (ft_isdigit(*index))
		{
			params.width = ft_atoi(index);
			index += ft_intlen(params.width) - 1;
		}
		else if (*index == '.')
		{
			++index;
			params.precision = ft_atoi(index);
			index += ft_intlen(params.precision) - 1;
		}
		else
		{
			tmp.format = (char *)index;
			bt = ft_btree_searchf(g_printf_formats, &tmp, sizeof(t_printf_format), formatcmp);
			if (bt)
			{
				tmp = *((t_printf_format *)(bt->content));
				index += ft_strlen(tmp.format) - 1;
				params.format = tmp.format;
				if (tmp.printfunc)
					tmp.printfunc(lst, params);
			}
			else
			{
				if (params.flags[MINUS_FLAG])
					ft_putchar(*index);
				ft_putnchar((params.flags[ZERO_FLAG] ? '0' : ' '),  params.width - 1);
				if (!params.flags[MINUS_FLAG])
					ft_putchar(*index);
			}
			break;
		}
		++index;
	}
	*format = index;
}

static int	ft_inner_printf(const char *format, va_list args)
{
	int	len;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			ft_printf_parse(&format, args);
		}
		else
		{
			++len;
			ft_putchar(*format);
		}
		++format;
	}
	return (len); 
}

int			ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	if (g_printf_formats == NULL)
	{
		ft_printf_add_format("s", handler_putstr);
		ft_printf_add_format("d", handler_putnbr);
		ft_printf_add_format("p", handler_putptr);
	}
	va_start(args, format);
	len = ft_inner_printf(format, args);
	va_end(args);
	return (len);
}

int		ft_printf_add_format(const char *f, t_printfunc func)
{
	t_printf_format	format;
	t_btree			*tmp;
	size_t			szfmt;

	szfmt = sizeof(t_printf_format);
	format.format = (char *)f;
	format.printfunc = func;
	if (!ft_btree_searchf(g_printf_formats, &format, szfmt, formatcmp))
	{
		tmp = ft_btree_new(&format, szfmt);
		tmp = ft_btree_insertf(g_printf_formats, tmp, formatcmp);
		if (g_printf_formats == NULL)
			g_printf_formats = tmp;
		return (1);
	}
	return (0);
}

void	ft_printf_free_formats()
{
	ft_btree_del(&g_printf_formats, NULL);
}
