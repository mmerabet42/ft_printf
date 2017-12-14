/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:17:07 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/14 23:31:14 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "handlers.h"

static t_ret	get_ret(char *buffer, int err)
{
	t_ret	ret;

	ret.len = ft_strlen(buffer);
	ret.err = err;
	ret.buf = ft_strrepc(buffer, -1, 0);
	return (ret);
}

t_ret			ft_inner_printf(const char *format, va_list ap)
{
	char	*cs;
	char	*tmp;
	t_ret	ret;

	ft_init_formats();
	cs = NULL;
	ret.buf = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			if (!(tmp = ft_printf_parser(&format, ret.buf ? ret.buf : cs, ap)))
			{
				ret = get_ret(ret.buf, 1);
				free(cs);
				return (ret);
			}
			ret.buf = ft_strjoin_clr(ft_strjoin_clr(ret.buf, cs, 2), tmp, 2);
			cs = NULL;
		}
		else
			cs = ft_strjoinc_clr(cs, *format++);
	}
	return (get_ret(ft_strjoin_clr(ret.buf, cs, 2), 0));
}

int				ft_vprintf_s(char **buffer, const char *format, va_list ap)
{
	t_ret	ret;

	if (!buffer || !format)
		return (-1);
	ret = ft_inner_printf(format, ap);
	*buffer = ret.buf;
	return (ret.len);
}

int				ft_vprintf_fd(int fd, const char *format, va_list ap)
{
	t_ret	ret;

	if (!format)
		return (-1);
	ret = ft_inner_printf(format, ap);
	write(fd, ret.buf, ret.len);
	free(ret.buf);
	return (ret.err ? -1 : ret.len);
}

int				ft_vprintf(const char *format, va_list ap)
{
	return (ft_vprintf_fd(1, format, ap));
}
