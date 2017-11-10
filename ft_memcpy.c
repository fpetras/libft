/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 06:55:20 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/09 08:16:29 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	i = 0;
	dest = (char*)dst;
	source = (char*)src;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
