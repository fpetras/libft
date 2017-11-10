/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:20:45 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/09 11:22:41 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *tmp;

	tmp = (char*)malloc(sizeof(char) * len);
	tmp = ft_memcpy(tmp, src, len);
	dst = ft_memcpy(dst, tmp, len);
	return (dst);
}
