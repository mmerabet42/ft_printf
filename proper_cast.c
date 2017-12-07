/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proper_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:48:04 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/07 19:07:00 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

long long			proper_cast(long long n, t_printf_params params)
{
	if (params.flags[J_MOD])
		n = (long long)((intmax_t)n);
	else if (params.flags[LL_MOD])
		n = (long long)n;
	else if (params.flags[L_MOD])
		n = (long long)((long)n);
	else if (params.flags[H_MOD])
		n = (long long)((short)n);
	else if (params.flags[HH_MOD])
		n = (long long)((char)n);
	else
		n = (long long)((int)n);
	return (n);
}

unsigned long long	proper_cast_u(unsigned long long n, t_printf_params params)
{
	if (params.flags[J_MOD])
		n = (unsigned long long)((intmax_t)n);
	else if (params.flags[LL_MOD])
		n = (unsigned long long)n;
	else if (params.flags[L_MOD])
		n = (unsigned long long)((unsigned long)n);
	else if (params.flags[H_MOD])
		n = (unsigned long long)((unsigned short)n);
	else if (params.flags[HH_MOD])
		n = (unsigned long long)((unsigned char)n);
	else
		n = (unsigned long long)((unsigned int)n);
	return (n);
}
