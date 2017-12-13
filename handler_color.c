/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:49:13 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/13 23:32:58 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_color(va_list lst, t_printf_params params)
{
	char	*color;
	char	*oldcolor;
	int		pos;

	(void)lst;
	if ((pos = ft_strchr_pos(*params.format, '}')) == -1)
		return (ft_strdup("{"));
	oldcolor = ft_strndup(*params.format, pos);
	*params.format += pos + 1;
	if (ft_strchr(oldcolor, '%'))
		return (ft_strjoincs_clr('{', oldcolor));
	color = ft_strtrim(oldcolor);
	free(oldcolor);
	return (ft_strjoin_clr("[{ ", ft_strjoin_clr(color, " }]", 0), 1));
}
