/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:01:04 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/11 20:57:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "ft_printf.h"
# include <stdio.h>

enum
{
	PLUS_FLAG, MINUS_FLAG, HASH_FLAG, ZERO_FLAG, SPACE_FLAG,
	L_MOD, LL_MOD, H_MOD, HH_MOD, J_MOD, T_MOD, Z_MOD,
	FLAGS_SIZE
};

typedef struct		s_printf_params
{
	char			*format;
	int				width;
	int				precision;
	int				precision_spec;
	int				flags[FLAGS_SIZE];
}					t_printf_params;

typedef char *(*t_printfunc)(va_list lst, t_printf_params params);

typedef struct		s_printf_format
{
	char			*format;
	t_printfunc		printfunc;
}					t_printf_format;

int					ft_printf_add_format(const char *f, t_printfunc func);
void				ft_printf_free_formats();
char				*ft_handle_format(va_list lst,
								const char **format,
								t_printf_params params);
char				*ft_printf_parser(const char **format, va_list lst);

char				*perform_width(char *str, t_printf_params *params);
char				*pad_zeroes(char *str, t_printf_params *params);
long long			proper_cast(va_list lst, t_printf_params params);
unsigned long long	proper_cast_u(va_list lst, t_printf_params params);

char				*handler_s(va_list lst, t_printf_params params);
char				*handler_s_m(va_list lst, t_printf_params params);
char				*handler_d(va_list lst, t_printf_params params);
char				*handler_d_m(va_list lst, t_printf_params params);
char				*handler_u(va_list lst, t_printf_params params);
char				*handler_u_m(va_list lst, t_printf_params params);
char				*handler_p(va_list lst, t_printf_params params);
char				*handler_x(va_list lst, t_printf_params params);
char				*handler_x_m(va_list lst, t_printf_params params);
char				*handler_o(va_list lst, t_printf_params params);
char				*handler_o_m(va_list lst, t_printf_params params);
char				*handler_c(va_list lst, t_printf_params params);
char				*handler_c_m(va_list lst, t_printf_params params);
char				*handler_f(va_list lst, t_printf_params params);
char				*handler_b(va_list lst, t_printf_params params);
char				*handler_r(va_list lst, t_printf_params params);

#endif
