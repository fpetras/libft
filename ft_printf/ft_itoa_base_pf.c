/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 07:29:30 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 09:47:48 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_itoa_base_pf(int fd, intmax_t value, int base)
{
	int			len;
	intmax_t	value2;
	char		*radix;
	char		*result;

	len = 1;
	value2 = value;
	if (value < -9223372036854775807)
		return (write(fd, "9223372036854775808", 19));
	while (value2 /= base)
		len++;
	radix = ft_strdup("0123456789ABCDEF");
	result = (char*)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[value % base];
		value /= base;
	}
	len = ft_strlen(result);
	write(fd, result, len);
	free(radix);
	free(result);
	return (len);
}
