/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:01:04 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/07 18:04:55 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "ft_printf.h"

char				*perform_width(char *str, t_printf_params params);
char				*pad_zeroes(char *str, t_printf_params *params);
long long			proper_cast(long long n, t_printf_params params);
unsigned long long	proper_cast_u(unsigned long long n, t_printf_params params);

char				*handler_s(va_list lst, t_printf_params params);
char				*handler_d(va_list lst, t_printf_params params);
char				*handler_d_m(va_list lst, t_printf_params params);
char				*handler_u(va_list lst, t_printf_params params);
char				*handler_u_m(va_list lst, t_printf_params params);
char				*handler_p(va_list lst, t_printf_params params);
char				*handler_x(va_list lst, t_printf_params params);
char				*handler_x_m(va_list lst, t_printf_params params);
char				*handler_o(va_list lst, t_printf_params params);
char				*handler_o_m(va_list lst, t_printf_params params);

#endif
