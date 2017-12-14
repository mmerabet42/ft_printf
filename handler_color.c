/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:49:13 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/14 18:55:40 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static char	*get_color(char *tcolor, int fb)
{
	if (ft_strequ(tcolor, "cyan") && !fb)
		return ("\e[36m");
	else if (ft_strequ(tcolor, "cyan") && fb)
		return ("\e[46m");
	else if (ft_strequ(tcolor, "black") && !fb)
		return ("\e[30m");
	else if (ft_strequ(tcolor, "black") && fb)
		return ("\e[40m");
	else if (ft_strequ(tcolor, "red") && !fb)
		return ("\e[31m");
	else if (ft_strequ(tcolor, "red") && fb)
		return ("\e[40m");
	return ("\e[0m");
}

static char	*perform_color(char *tcolor)
{
	char	esc_fb[11];
	char	*oldcolor;
	int		r;
	int		fb;

	r = 0;
	fb = 0;
	ft_strcpy(esc_fb, "\e[38;5;");
	oldcolor = tcolor;
	if (*tcolor == 'r')
	{
		++tcolor;
		r = 1;
	}
	if (*tcolor == 'b')
	{
		ft_strncpy(esc_fb + 2, "48", 2);
		fb = 1;
	}
	while (*(tcolor - 1) != ':' && *tcolor)
		++tcolor;
	tcolor = (r ? ft_strjoin_clr(esc_fb, ft_strjoinc(tcolor, 'm'), 1)
			: ft_strdup(get_color(tcolor, fb)));
	//ft_printf("\nL: '%s'\n", tcolor);
	free(oldcolor);
	return (tcolor);
}

char		*handler_color(va_list lst, t_printf_params params)
{
	char	*color;
	char	*tcolor;
	int		pos;

	if ((pos = ft_strchr_pos(*params.format, '}')) == -1)
		return (ft_strdup("{"));
	color = ft_strndup(*params.format, pos);
	*params.format += pos + 1;
	tcolor = ft_strtrim_clr(ft_inner_printf(color, lst).buf);
	free(color);
	return (perform_color(tcolor));
}
