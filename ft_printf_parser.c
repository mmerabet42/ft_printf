/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:03:19 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/10 23:22:25 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static int	ft_is_flag(char c, t_printf_params *params)
{
	if (c == '#')
		return (params->flags[HASH_FLAG] = 1);
	else if (c == '+')
		return (params->flags[PLUS_FLAG] = 1);
	else if (c == '-')
		return (params->flags[MINUS_FLAG] = 1);
	else if (c == '0')
		return (params->flags[ZERO_FLAG] = 1);
	else if (c == ' ')
		return (params->flags[SPACE_FLAG] = 1);
	return (0);
}

static int	ft_is_width(const char **index, t_printf_params *params,
					va_list lst)
{
	if (ft_isdigit(**index))
	{
		params->width = ft_atoi(*index);
		while (ft_isdigit(**index))
			++(*index);
		return (1);
	}
	else if (**index == '*')
	{
		if ((params->width = (int)va_arg(lst, int)) < 0)
		{
			params->width = ft_abs(params->width);
			params->flags[MINUS_FLAG] = 1;
		}
		++(*index);
		return (1);
	}
	return (0);
}

static int	ft_is_precision(const char **index, t_printf_params *params,
						va_list lst)
{
	if (**index == '.')
	{
		params->precision_spec = 1;
		if (ft_isdigit(*++(*index)))
		{
			params->precision = ft_atoi(*index);
			while (ft_isdigit(**index))
				++(*index);
		}
		else if (**index == '*')
		{
			params->precision = (int)va_arg(lst, int);
			++(*index);
			return (1);
		}
		else
			params->precision = 0;
		return (1);
	}
	return (0);
}

static int	ft_is_modifier(const char **index, t_printf_params *params)
{
	int ret;

	ret = 1;
	if (ft_strnequ("ll", *index, 2))
	{
		*index += 2;
		return (params->flags[LL_MOD] = 1);
	}
	else if (ft_strnequ("hh", *index, 2))
	{
		*index += 2;
		return (params->flags[HH_MOD] = 1);
	}
	else if (**index == 'l')
		params->flags[L_MOD] = 1;
	else if (**index == 'h')
		params->flags[H_MOD] = 1;
	else if (**index == 'j')
		params->flags[J_MOD] = 1;
	else if (**index == 'z')
		params->flags[Z_MOD] = 1;
	else
		ret = 0;
	*index += ret;
	return (ret);
}

char		*ft_printf_parser(const char **format, va_list lst)
{
	t_printf_params	params;

	ft_bzero(&params, sizeof(t_printf_params));
	++(*format);
	while (**format)
	{
		if (ft_is_flag(**format, &params))
			++(*format);
		else if (ft_is_width(format, &params, lst))
			;
		else if (ft_is_precision(format, &params, lst))
			;
		else if (ft_is_modifier(format, &params))
			;
		else
			return (ft_handle_format(lst, format, params));
	}
	return (NULL);
}
