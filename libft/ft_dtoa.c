/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:12:56 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/11 13:15:37 by mmerabet         ###   ########.fr       */
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
		while (kprec--)
			secondp *= 10;
		kprec = precision;
		precision_adder = 0.1;
		while (kprec--)
			precision_adder /= 10;
		if (secondp == 0)
			cps[1] = (char *)ft_memset(ft_strnew(precision), '0', precision);
		else
			cps[1] = ft_ulltoa((unsigned long long)(secondp + precision_adder));
		cps[0] = ft_strjoin_clr(ft_strjoinc_clr(cps[0], '.'), cps[1], 2);
	}
	return (cps[0]);
}
