/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_putptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:12:58 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/02 22:17:46 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_handlers.h"

char	*handler_putptr(va_list lst, t_printf_params params)
{
	char	*str;
	void	*ptr;

	ptr = va_arg(lst, void *);
	str = ft_ulltoa((unsigned long long)ptr);
}
