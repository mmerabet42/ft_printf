/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:49:13 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/14 23:47:45 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static char	*exit_clean(char *tcolor)
{
	free(tcolor);
	return (ft_strdup("\e[0m"));
}

static char	*get_color(char *tcolor, int fb)
{
	char	fcolor[7];

	ft_strcpy(fcolor, "\e[30m");
	if (ft_strequ(tcolor, "black"))
		fcolor[3] = '0';
	else if (ft_strequ(tcolor, "red"))
		fcolor[3] = '1';
	else if (ft_strequ(tcolor, "green"))
		fcolor[3] = '2';
	else if (ft_strequ(tcolor, "yellow"))
		fcolor[3] = '3';
	else if (ft_strequ(tcolor, "blue"))
		fcolor[3] = '4';
	else if (ft_strequ(tcolor, "magenta"))
		fcolor[3] = '5';
	else if (ft_strequ(tcolor, "cyan"))
		fcolor[3] = '6';
	else if (ft_strequ(tcolor, "lgray"))
		fcolor[3] = '7';
	else
		return (exit_clean(tcolor));
	if (fb)
		fcolor[2] = '4';
	free(tcolor);
	return (ft_strdup(fcolor));
}

static char	*check(char *tcolor)
{
	char	*tmp;

	tmp = tcolor;
	while (ft_isdigit(*tcolor))
		++tcolor;
	if (*tcolor == '\0')
		return (tmp);
	return (NULL);
}

static char	*perform_color(char *tcolor, t_printf_params params)
{
	char	esc_fb[11];

	if (params.flags[MINUS_FLAG])
	{
		free(tcolor);
		return (ft_strdup("\e[0m"));
	}
	ft_strcpy(esc_fb, "\e[38;5;");
	if (params.flags[HASH_FLAG] && params.flags[ZERO_FLAG])
		ft_strncpy(esc_fb + 2, "48", 2);
	if (params.flags[ZERO_FLAG])
		tcolor = ft_strjoin_clr(esc_fb, ft_strjoinc_clr(check(tcolor), 'm'), 1);
	else
		tcolor = get_color(tcolor, params.flags[HASH_FLAG]);
	char *fbfr;
	ft_printf_s(&fbfr, "\e[%c8;5;%sm", (params.flags[HASH_FLAG] ? '4' : '3'), 
	return (tcolor);
}

char		*handler_color(va_list lst, t_printf_params params)
{
	char	*color;
	char	*tcolor;
	int		pos;

	if ((pos = ft_strchr_pos(*params.format, '}')) == -1)
		return (ft_strdup("{"));
	if (params.precision_spec && !params.flags[HASH_FLAG])
		params.flags[HASH_FLAG] = params.precision;
	if (params.width)
		params.flags[ZERO_FLAG] = 1;
	color = ft_strndup(*params.format, pos);
	*params.format += pos + 1;
	tcolor = ft_strtrim_clr(ft_inner_printf(color, lst).buf);
	free(color);
	return (perform_color(tcolor, params));
}
