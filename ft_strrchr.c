/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:32:23 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/09 06:38:37 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	value;
	char	*str;

	len = ft_strlen(s);
	value = (char)c;
	str = (char*)s;
	while (len >= 0)
	{
		if (str[len] == value)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
