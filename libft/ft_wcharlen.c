/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:06:55 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/12 09:50:25 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcharlen(wchar_t c)
{
	if (c <= 0x7f && MB_CUR_MAX >= 1)
		return (1);
	else if (c <= 0x7ff && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 0xffff && MB_CUR_MAX >= 3)
		return (3);
	else if (c <= 0x10ffff && MB_CUR_MAX >= 4)
		return (4);
	return (0);
}
