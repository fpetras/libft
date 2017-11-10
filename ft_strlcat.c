/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:06:54 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/09 07:10:53 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	if (size < j)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && i < (size - ft_strlen(dst) - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (j + ft_strlen(src));
}
