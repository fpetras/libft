/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 07:29:30 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/04 11:42:11 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(int value, int base)
{
	int		i;

	i = 0;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

static char	*itoa_base(int value, int base, int len, int n)
{
	char	*radix;
	char	*result;

	radix = ft_strdup("0123456789ABCDEF");
	result = (char*)malloc(sizeof(char) * (len + n + 1));
	if (result == NULL)
		return (NULL);
	if (n == 1)
	{
		result[0] = '-';
		len++;
	}
	result[len] = '\0';
	while (len > n)
	{
		result[len - 1] = radix[value % base];
		len--;
		value /= base;
	}
	free(radix);
	return (result);
}

char		*ft_itoa_base(int value, int base)
{
	int		len;
	int		n;

	n = 0;
	if (value == 0)
		return (ft_strdup("0"));
	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	if (base < 2 || base > 16)
		return (NULL);
	if (value < 0 && base != 10)
		return (NULL);
	if (value < 0 && base == 10)
	{
		n = 1;
		value *= -1;
	}
	len = ft_nbr_len(value, base);
	return (itoa_base(value, base, len, n));
}
