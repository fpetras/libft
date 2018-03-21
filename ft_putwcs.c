/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:26:52 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 11:25:46 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwcs(const wchar_t *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 0 && s[i] <= 127)
			;
		else if (s[i] >= 0 && s[i] <= 255 && MB_CUR_MAX == 1)
			;
		else if (s[i] >= 128 && s[i] <= 2047 && MB_CUR_MAX >= 2)
			;
		else if (s[i] >= 2048 && s[i] <= 65535 && MB_CUR_MAX >= 3)
			;
		else if (s[i] >= 65536 && s[i] <= 1114111 && MB_CUR_MAX == 4)
			;
		else
			return ;
		i++;
	}
	i = 0;
	while (s[i])
	{
		ft_putwchar(s[i]);
		i++;
	}
}
