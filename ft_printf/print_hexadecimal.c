/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:06:19 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 09:42:38 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex_left_align(intmax_t nbr, t_struct *f, char letter)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16);
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		while (f->width)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
		return ;
	}
	if (f->hash && nbr != 0)
		nbrlen += 2;
	if (f->hash && letter == 'x' && nbr != 0)
		f->len += write(f->fd, "0x", 2);
	else if (f->hash && letter == 'X' && nbr != 0)
		f->len += write(f->fd, "0X", 2);
	while (nbrlen++ < f->precision)
		f->len += write(f->fd, "0", 1);
	f->len += ft_uitoa_base_pf(f->fd, nbr, 16, letter);
	while (f->width-- >= nbrlen)
		f->len += write(f->fd, " ", 1);
}

static void	ft_padding(int nbrlen, t_struct *f)
{
	if (!f->precision_specified)
		while (f->width-- > nbrlen)
		{
			if (f->zero)
				f->len += write(f->fd, "0", 1);
			else
				f->len += write(f->fd, " ", 1);
		}
	else
	{
		if (f->plus || f->zero)
			f->width--;
		while (f->width-- > nbrlen)
		{
			if (f->zero)
				f->len += write(f->fd, "0", 1);
			else
				f->len += write(f->fd, " ", 1);
		}
	}
}

static void	ft_prefix(uintmax_t nbr, t_struct *f, char letter)
{
	if (f->hash && letter == 'x' && nbr != 0)
		f->len += write(f->fd, "0x", 2);
	else if (f->hash && letter == 'X' && nbr != 0)
		f->len += write(f->fd, "0X", 2);
}

static void	ft_print_hex_right_align(uintmax_t nbr, t_struct *f, char letter)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16);
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		while (f->width)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
		return ;
	}
	if (f->hash && nbr != 0)
		nbrlen += 2;
	if (f->hash && f->zero)
		ft_prefix(nbr, f, letter);
	ft_padding(nbrlen, f);
	while (nbrlen++ < f->precision)
		f->len += write(f->fd, "0", 1);
	if (f->hash && !f->zero)
		ft_prefix(nbr, f, letter);
	f->len += ft_uitoa_base_pf(f->fd, nbr, 16, letter);
}

void		ft_print_hex(char type, t_struct *f, va_list ap)
{
	uintmax_t nbr;

	if (type == 'x' || type == 'X')
	{
		if (!f->length)
			nbr = va_arg(ap, unsigned int);
		else if (f->length == HH)
			nbr = (unsigned char)va_arg(ap, unsigned int);
		else if (f->length == H)
			nbr = (unsigned short)va_arg(ap, unsigned int);
		else if (f->length == L)
			nbr = va_arg(ap, unsigned long);
		else if (f->length == LL)
			nbr = va_arg(ap, unsigned long long);
		else if (f->length == J)
			nbr = va_arg(ap, uintmax_t);
		else if (f->length == Z)
			nbr = va_arg(ap, size_t);
		if (f->minus)
			ft_print_hex_left_align(nbr, f, type);
		else
			ft_print_hex_right_align(nbr, f, type);
	}
}
