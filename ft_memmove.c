/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:20:45 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/11 16:54:03 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	if (&dst[0] < &src[0])
		return (ft_memcpy(dst, src, len));
	dest = (char*)dst;
	source = (char*)src;
	while (len > 0)
	{
		dest[len - 1] = source[len - 1];
		len--;
	}
	return (dest);
}
