/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:56:04 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/08 17:43:23 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_s(va_list lst, t_printf_params params)
{
	char	*gs;
	int		slen;

	gs = va_arg(lst, char *);
	if (!gs)
		gs = "(null)";
	slen = ft_strlen(gs);
	if (params.precision_spec && params.precision < slen)
		slen = params.precision;
	gs = ft_strndup(gs, slen);
	return (perform_width(gs, params));
}
