#include "ft_printf.h"
#include "printf_handlers.h"
#include <stdio.h>

static t_btree	*g_printf_formats = NULL;

static int	formatcmp(const void *a, const void *b, size_t n)
{
	(void)n;
	t_printf_format	*fa = (t_printf_format *)a;
	t_printf_format	*fb = (t_printf_format *)b;
	return (ft_strncmp(fa->format, fb->format, ft_strlen(fa->format)));
}

static int	ft_is_flag(char c, t_printf_params *params)
{
	if (c == '#')
		return (params->flags[HASH_FLAG] = 1);
	else if (c == '+')
		return (params->flags[PLUS_FLAG] = 1);
	else if (c == '-')
		return (params->flags[MINUS_FLAG] = 1);
	else if (c == '0')
		return (params->flags[ZERO_FLAG] = 1);
	else if (c == ' ')
		return (params->flags[SPACE_FLAG] = 1);
	return (0);
}

static int	ft_is_precision(const char **index, t_printf_params *params)
{
	if (**index == '.')
	{
		params->precision_spec = 1;
		if (ft_isdigit(*++(*index)))
		{
			params->precision = ft_atoi(*index);
			while (ft_isdigit(**index))
				++(*index);
		}
		else
			params->precision = 0;
		return (1);
	}
	return (0);
}

static t_printf_format	*ft_get_format(const char *format)
{
	t_printf_format	tmp;
	t_btree			*bt;

	tmp.format = (char *)format;
	bt = ft_btree_searchf(g_printf_formats, &tmp, sizeof(t_printf_format), formatcmp);
	if (bt)
		return ((t_printf_format *)bt->content);
	return (NULL);
}

static char	*ft_printf_parser(const char **format, va_list lst)
{
	const char		*index;
	char			*buffer;
	t_printf_params	params;
	t_printf_format	*tmp;

	buffer = NULL;
	index = *format;
	ft_bzero(&params, sizeof(t_printf_params));
	while (*index)
	{
		if (ft_is_flag(*index, &params))
			++index;
		else if (ft_isdigit(*index))
		{
			params.width = ft_atoi(index);
			while (ft_isdigit(*index))
				++index;
		}
		else if (ft_is_precision(&index, &params))
			;
		else
		{
			printf("l: %s\n", index);
			if ((tmp = ft_get_format(index)))
			{
				if (tmp->printfunc)
					buffer = tmp->printfunc(lst, params);
				index += ft_strlen(tmp->format) - 1;
			}
			else
			{
				params.width = (params.width == 0 ? 0 : params.width - 1);
				if (params.flags[MINUS_FLAG])
					buffer = ft_strjoinc_clr(buffer, *index);
				buffer = ft_strjoin_clr(buffer, ft_memset(ft_strnew(params.width), ' ', params.width), 2);
				ft_memset(buffer + (params.flags[MINUS_FLAG] ? 1 : 0), params.flags[ZERO_FLAG] && !params.flags[MINUS_FLAG] ? '0' : ' ', params.width);
				if (!params.flags[MINUS_FLAG])
					buffer = ft_strjoinc_clr(buffer, *index);
			}
			break;
		}
	}
	*format = index;
	return (buffer);
}

static int	ft_inner_printf(const char *format, va_list args)
{
	char	*buffer;
	int		len;

	buffer = NULL;
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			buffer = ft_strjoin_clr(buffer, ft_printf_parser(&format, args), 2);
		}
		else
			buffer = ft_strjoinc_clr(buffer, *format);
		++format;
	}
	len = ft_strlen(buffer);
	ft_putstr(buffer);
	free(buffer);
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
