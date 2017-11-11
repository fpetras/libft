/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:56:24 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/10 13:28:42 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trimmed;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (s[start] && ft_isspace(s[start]))
		start++;
	while (start < end && s[end - 1] && ft_isspace(s[end - 1]))
		end--;
	if (!(trimmed = (char*)malloc(sizeof(char) * ((end - start) + 1))))
		return (NULL);
	while (i < (end - start))
	{
		trimmed[i] = s[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
