/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:12:56 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/13 22:05:31 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double n, int precision)
{
	long long	firstp;
	double		secondp;
	char		*cps[2];
	int			kprec;
	double		precision_adder;

	kprec = precision;
	firstp = (long long)n;
	secondp = (double)(n - firstp) * (n < 0 ? -1 : 1);
	cps[0] = ft_lltoa(firstp);
	if (precision > 0)
	{
		cps[1] = ft_strnew(kprec);
		precision_adder = 0.05;
		while (kprec-- > 1)
			precision_adder /= 10;
		secondp += precision_adder;
		while (kprec < precision)
		{
			secondp *= 10;
			cps[1][kprec++] = ((unsigned long long)secondp % 10) + 48;
		}
		cps[0] = ft_strjoin_clr(ft_strjoinc_clr(cps[0], '.'), cps[1], 2);
	}
	return (cps[0]);
}

char	*ft_ldtoa(long double n, int precision)
{
	long long	firstp;
	long double	secondp;
	char		*cps[2];
	int			kprec;
	long double	precision_adder;

	kprec = precision;
	firstp = (long long)n;
	secondp = (long double)(n - firstp) * (n < 0 ? -1 : 1);
	cps[0] = ft_lltoa(firstp);
	if (precision > 0)
	{
		cps[1] = ft_strnew(kprec);
		precision_adder = 0.05;
		while (kprec-- > 1)
			precision_adder /= 10;
		secondp += precision_adder;
		while (kprec < precision)
		{
			secondp *= 10;
			cps[1][kprec++] = ((unsigned long long)secondp % 10) + 48;
			secondp -= (unsigned long long)(secondp / 10) * 10;
		}
		cps[0] = ft_strjoin_clr(ft_strjoinc_clr(cps[0], '.'), cps[1], 2);
	}
	return (cps[0]);
}
