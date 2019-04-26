/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:46:18 by fpetras           #+#    #+#             */
/*   Updated: 2019/03/27 15:57:24 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (ft_tolower(s1[i]) != '\0' && ft_tolower(s2[i]) != '\0' &&
		ft_tolower(s1[i]) == ft_tolower(s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)ft_tolower(s1[i]) -
		(unsigned char)ft_tolower(s2[i]));
}
