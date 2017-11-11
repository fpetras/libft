/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:38:30 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/10 12:09:45 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	if (s[i] != c)
		nb++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_len(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	**ft_split(char const *s, char c, size_t i, size_t j)
{
	size_t	k;
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * ft_count(s, c) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			k = 0;
			if (!(tab[j] = (char*)malloc(sizeof(char) * ft_len(&s[i], c) + 1)))
				return (NULL);
			while (s[i] != '\0' && s[i] != c)
				tab[j][k++] = s[i++];
			tab[j][k] = '\0';
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	return (ft_split(s, c, i, j));
}
