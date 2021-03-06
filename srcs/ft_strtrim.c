/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:55:25 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/14 22:48:32 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int	len;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		++s;
	len = ft_strlen(s) - 1;
	while (len >= 0 && ft_isspace(s[len]))
		--len;
	return (ft_strndup(s, len + 1));
}

char	*ft_strtrim_clr(char *s)
{
	char	*str;
	char	*tmp;
	int		len;

	tmp = s;
	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		++s;
	len = ft_strlen(s) - 1;
	while (len >= 0 && ft_isspace(s[len]))
		--len;
	str = ft_strndup(s, len + 1);
	free(tmp);
	return (str);
}
