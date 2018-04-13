/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:43:21 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/13 17:14:37 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (ft_tolower(s1[i]) != '\0' && ft_tolower(s2[i]) != '\0' &&
		ft_tolower(s1[i]) == ft_tolower(s2[i]))
		i++;
	return ((unsigned char)ft_tolower(s1[i]) -
		(unsigned char)ft_tolower(s2[i]));
}
