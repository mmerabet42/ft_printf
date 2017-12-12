/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:27:31 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/11 22:37:00 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getwstr(const wchar_t *wcs)
{
	char	*str;

	str = ft_strnew(0);
	if (!wcs)
		return (NULL);
	while (*wcs)
		str = ft_strjoin_clr(str, ft_getwchar(*wcs++), 2);
	return (str);
}