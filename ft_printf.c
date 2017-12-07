/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:27:32 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/07 22:43:25 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "handlers.h"

static t_btree	*g_printf_formats = NULL;

static int	formatcmp(const void *a, const void *b, size_t n)
{
	(void)n;
	t_printf_format	*fa = (t_printf_format *)a;
	t_printf_format	*fb = (t_printf_format *)b;
	return (ft_strncmp(fa->format, fb->format, ft_strlen(fa->format)));
}

static int		ft_is_flag(char c, t_printf_params *params)
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

static int		ft_is_precision(const char **index, t_printf_params *params)
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

static int		ft_is_modifier(const char **index, t_printf_params *params)
{
	if (ft_strnequ("ll", *index, 2))
	{
		*index += 2;
		return (params->flags[LL_MOD] = 1);
	}
	else if (ft_strnequ("l", *index, 1))
	{
		++(*index);
		return (params->flags[L_MOD] = 1);
	}
	else if (ft_strnequ("hh", *index, 2))
	{
		*index += 2;
		return (params->flags[HH_MOD] = 1);
	}
	else if (ft_strnequ("h", *index, 1))
	{
		++(*index);
		return (params->flags[H_MOD] = 1);
	}
	else if (ft_strnequ("j", *index, 1))
	{
		++(*index);
		return (params->flags[J_MOD] = 1);
	}
	else if (ft_strnequ("z", *index, 1))
	{
		++(*index);
		return (params->flags[Z_MOD] = 1);
	}
	return (0);
}

static char		*ft_handle_format(va_list lst, const char **format, t_printf_params params)
{
	char		*buffer;
	t_printf_format	tmp;
	t_btree		*bt;

	buffer = NULL;
	tmp.format = (char *)*format;
	bt = ft_btree_searchf(g_printf_formats, &tmp, sizeof(t_printf_format), formatcmp);
	if (bt)
	{
		tmp = *(t_printf_format *)bt->content;
		*format += ft_strlen(tmp.format);
		if (tmp.printfunc)
			return (tmp.printfunc(lst, params));
	}
	else
		buffer = perform_width(ft_strjoinc_clr(NULL, **format), params);
	++(*format);
	return (buffer);
}

static char		*ft_printf_parser(const char **format, va_list lst)
{
	t_printf_params	params;

	ft_bzero(&params, sizeof(t_printf_params));
	++(*format);
	while (**format)
	{
		if (ft_is_flag(**format, &params))
			++(*format);
		else if (ft_isdigit(**format))
		{
			params.width = ft_atoi(*format);
			while (ft_isdigit(**format))
				++(*format);
		}
		else if (ft_is_precision(format, &params))
			;
		else if (ft_is_modifier(format, &params))
			;
		else
			return (ft_handle_format(lst, format, params));
	}
	return (NULL);
}

static int		ft_inner_printf(const char *format, va_list args)
{
	char	*buffer;
	int		len;

	buffer = ft_strdup("");
	len = 0;
	while (*format)
	{
		if (*format == '%')
			buffer = ft_strjoin_clr(buffer, ft_printf_parser(&format, args), 2);
		else
			buffer = ft_strjoinc_clr(buffer, *format++);
	}
	len = ft_strlen(buffer);
	ft_putstr(buffer);
	free(buffer);
	return (len); 
}

int				ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	if (g_printf_formats == NULL)
	{
		ft_printf_add_format("s", handler_s);
		ft_printf_add_format("i", handler_d);
		ft_printf_add_format("d", handler_d);
		ft_printf_add_format("D", handler_d_m);
		ft_printf_add_format("u", handler_u);
		ft_printf_add_format("U", handler_u_m);
		ft_printf_add_format("p", handler_p);
		ft_printf_add_format("x", handler_x);
		ft_printf_add_format("X", handler_x_m);
		ft_printf_add_format("o", handler_o);
		ft_printf_add_format("O", handler_o_m);
		ft_printf_add_format("c", handler_c);
	}
	va_start(args, format);
	len = ft_inner_printf(format, args);
	va_end(args);
	return (len);
}

int				ft_printf_add_format(const char *f, t_printfunc func)
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

void			ft_printf_free_formats()
{
	ft_btree_del(&g_printf_formats, NULL);
}
