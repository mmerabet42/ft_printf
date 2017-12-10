/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:59:21 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/10 21:58:21 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*perform_width(char *str, t_printf_params *params)
{
	char	*s;
	int		len;

	len = params->width - ft_strlen(str);
	s = NULL;
	if (len > 0)
		s = ft_memset(ft_memalloc(len + 1), ' ', len);
	if (params->flags[ZERO_FLAG] && !params->flags[MINUS_FLAG] && s)
		s = ft_memset(s, '0', len);
	if (params->flags[MINUS_FLAG])
		s = ft_strjoin_clr(str, s, 2);
	else
		s = ft_strjoin_clr(s, str, 2);
	return (s);
}
