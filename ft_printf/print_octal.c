/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:06:19 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 09:41:30 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_octal_left_align(intmax_t nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 8);
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		while (f->width)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
		if (!f->hash)
			return ;
	}
	if (f->hash && nbr != 0)
	{
		f->len += write(f->fd, "0", 1);
		nbrlen++;
	}
	while (nbrlen++ < f->precision)
		f->len += write(f->fd, "0", 1);
	f->len += ft_uitoa_base_pf(f->fd, nbr, 8, 0);
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

static void	ft_print_octal_right_align(uintmax_t nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 8);
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		if (f->hash)
			f->len += write(f->fd, "0", 1);
		while (f->width)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
		return ;
	}
	if (f->hash && nbr != 0)
		nbrlen++;
	ft_padding(nbrlen, f);
	while (nbrlen++ < f->precision)
		f->len += write(f->fd, "0", 1);
	if (f->hash && nbr != 0)
		f->len += write(f->fd, "0", 1);
	f->len += ft_uitoa_base_pf(f->fd, nbr, 8, 0);
}

void		ft_print_octal(char type, t_struct *f, va_list ap)
{
	uintmax_t nbr;

	if (type == 'o' || type == 'O')
	{
		if (type == 'O')
			nbr = va_arg(ap, unsigned long);
		else if (!f->length)
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
			ft_print_octal_left_align(nbr, f);
		else
			ft_print_octal_right_align(nbr, f);
	}
}
