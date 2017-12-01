/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:59:21 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/01 19:28:13 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_handlers.h"

char	*replace_width(char *str, t_printf_params params)
{
	char	*s;
	int		len;

	len = params.width - ft_strlen(str);
	len = (len < 0 ? 0 : len);
	s = ft_memset(ft_strnew(len), ' ', len);
	if (params.flags[ZERO_FLAG] && !params.flags[MINUS_FLAG])
		ft_memset(s, '0', len);
	if (params.flags[MINUS_FLAG])
		s = ft_strjoin_clr(str, s, 2);
	else
		s = ft_strjoin_clr(s, str, 2);
	return (s);
}
