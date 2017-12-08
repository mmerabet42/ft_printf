/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_zeroes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:54:50 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/09 00:37:38 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*pad_zeroes(char *str, t_printf_params *params)
{
	int		len;
	int		zeroes;
	char	*zstr;

	len = ft_strlen(str);
	zeroes = 0;
	zstr = NULL;
	if (params->precision_spec)
	{
		params->flags[ZERO_FLAG] = 0;
		zeroes = params->precision - len;
	}
	else if (params->flags[ZERO_FLAG] && !params->flags[MINUS_FLAG])
		zeroes = params->width - len;
	zeroes = (zeroes < 0 ? 0 : zeroes);
	if (zeroes != 0)
		zstr = (char *)ft_memset(ft_memalloc(zeroes + 1), '0', zeroes);
	return (ft_strjoin_clr(zstr, str, 2));
}
