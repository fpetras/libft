/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:05:03 by fpetras           #+#    #+#             */
/*   Updated: 2018/02/05 12:26:01 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strreplace2(char *search, char *replace, char *subject,
							char *result)
{
	int i;
	int j;
	int start_pos;

	i = -1;
	start_pos = ft_strstr(subject, search) - subject;
	while (++i < start_pos)
		result[i] = subject[i];
	j = i;
	i = 0;
	while (replace[i])
	{
		result[j] = replace[i];
		j++;
		i++;
	}
	i = ft_strlen(search);
	while (subject[start_pos + i])
	{
		result[j] = subject[start_pos + i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char		*ft_strreplace(char *search, char *replace, char *subject)
{
	int		len;
	char	*result;

	if (!search || !replace || !subject)
		return (NULL);
	if (!ft_strstr(subject, search))
		return (NULL);
	len = ft_strlen(subject) - ft_strlen(search) + ft_strlen(replace);
	if (!(result = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	return (ft_strreplace2(search, replace, subject, result));
}
