/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:12:13 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/08 09:32:10 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	value;
	char	*str;

	i = 0;
	value = (char)c;
	str = (char*)s;
	while (str[i] != '\0')
	{
		if (str[i] == value)
			return (&str[i]);
		i++;
	}
	if (value == '\0')
		return (&str[i]);
	return (NULL);
}
