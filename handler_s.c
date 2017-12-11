/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:56:04 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/11 21:09:58 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_s(va_list lst, t_printf_params params)
{
	char	*gs;
	int		slen;

	gs = (char *)va_arg(lst, char *);
	if (!gs)
		gs = "(null)";
	slen = ft_strlen(gs);
	if (params.precision_spec && params.precision < slen
			&& params.precision >= 0)
		slen = params.precision;
	gs = ft_strndup(gs, slen);
	return (perform_width(gs, &params));
}

char	*handler_s_m(va_list lst, t_printf_params params)
{
	wchar_t	*ws;
	char	*gs;
	char	*str;
	char	*ostr;
	int		slen;

	ws = (wchar_t *)va_arg(lst, wchar_t *);
	gs = ft_getwstr(ws);
	if (!gs)
		str = "(null)";
	else
		str = gs;
	slen = ft_strlen(str);
	if (params.precision_spec && params.precision < slen)
		slen = params.precision;
	ostr = str;
	str = ft_strndup(ostr, slen);
	if (gs)
		free(ostr);
	return (perform_width(str, &params));
}
