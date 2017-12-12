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

#include  <stdio.h>
#include  <stdlib.h>
 
int main(void)
{
 int color;
 int green, red, blue;
 
 /* 0 - 15 */
 puts("System colors:");
 for(color = 0; color<8; color++)
 {
   printf("\x1B[48;5;%dm  ", color);
 }
 puts("\x1B[0m");
 for(color = 8; color<16; color++)
 {
   printf("\x1B[48;5;%dm  ", color);
 }
 puts("\x1B[0m\n");
 
 /* 16 - 231 */
 puts("Color cube, 6x6x6:");
 for(red = 0; red<6; red++)
 {
   for(green = 0; green<6; green++)
   {
     for(blue = 0; blue<6; blue++)
     {
       color = 16 + (red * 36) + (green * 6) + blue;
       printf("\x1B[48;5;%dm  ", color);
     }
     printf("\x1B[0m ");
   }
   puts("");
 }

#endif
