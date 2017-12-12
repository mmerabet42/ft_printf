/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:38:59 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/12 18:17:52 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printf_fd(int fd, const char *format, ...);
int		ft_printf_s(char **buffer, const char *format, ...);

int   ft_vprintf(const char *format, va_list ap);
int   ft_vprintf_fd(int fd, const char *format, va_list ap);
int   ft_vprintf_s(char **buffer, const char *format, va_list ap);

#endif
