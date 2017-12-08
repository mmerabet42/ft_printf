/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:48:48 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/08 18:23:38 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *a, const char *b)
{
	size_t	i;

	if (!a || !b)
		return (NULL);
	i = ft_strlen(a);
	while (*b)
		a[i++] = *b++;
	a[i] = '\0';
	return (a);
}
