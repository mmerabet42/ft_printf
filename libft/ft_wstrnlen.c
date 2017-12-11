/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:55:45 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/11 21:56:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstrnlen(const wchar_t *wstr, int n)
{
	int	i;
	int	len;

	i = 0;
	if (wstr)
	{
		while (*wstr)
		{
			len = ft_wcharlen(*wstr);
			if (i + len > n)
				return (i);
			i += len;
			++wstr;
		}
	}
	return (i);
}
