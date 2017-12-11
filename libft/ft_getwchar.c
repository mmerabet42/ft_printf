/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:09:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/11 19:42:32 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getwchar(wchar_t wc)
{
	char	wcs[4];

	if (ft_wcharlen(wc) == 0)
		return (NULL);
	ft_bzero(wcs, 4);
	if (wc <= 0x7F)
		wcs[0] = (char)wc;
	else if (wc <= 0x7FF)
	{
		wcs[0] = (char)((wc >> 6) | 0xC0);
		wcs[1] = (char)((wc & 0x3F) | 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		wcs[0] = (char)((wc >> 12) | 0xE0);
		wcs[1] = (char)(((wc >> 6) & 0x3F) | 0x80);
		wcs[2] = (char)((wc & 0x3F) | 0x80);
	}
	else if (wc <= 0x10FFFF)
	{
		wcs[0] = (char)((wc >> 18) | 0xF0);
		wcs[1] = (char)(((wc >> 12) & 0x3F) | 0x80);
		wcs[2] = (char)(((wc >> 6) & 0x3F) | 0x80);
		wcs[3] = (char)((wc & 0x3F) | 0x80);
	}
	return (ft_strdup(wcs));
}
