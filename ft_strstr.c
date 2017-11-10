/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:02:58 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/08 10:17:48 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	i = 0;
	h = (char*)haystack;
	n = (char*)needle;
	if (n[0] == '\0')
		return (h);
	while (h[i] != '\0')
	{
		j = 0;
		while (h[i + j] == n[j])
		{
			if (n[j + 1] == '\0')
				return (&h[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
