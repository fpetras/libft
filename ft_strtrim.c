/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:56:24 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/10 09:49:18 by fpetras          ###   ########.fr       */
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
	end = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
		end--;
	trimmed = (char*)malloc(sizeof(char) * ((end - start) + 1));
	if (trimmed == NULL)
		return (NULL);
	while (i < (end - start))
	{
		trimmed[i] = s[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
