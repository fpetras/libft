/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:06:19 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 09:36:46 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_decimal_left2(intmax_t nbr, int n, t_struct *f)
{
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		if (f->plus && f->width)
			f->width--;
		if (f->plus)
			f->len += write(f->fd, "+", 1);
		while (f->width)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
		return (1);
	}
	if (f->space && n == 0)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
	return (0);
}

static void	ft_print_decimal_left_align(intmax_t nbr, t_struct *f)
{
	int nbrlen;
	int n;

	nbrlen = ft_signed_nbr_len(nbr, 10);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (ft_decimal_left2(nbr, n, f))
		return ;
	if (f->plus && n == 0)
	{
		f->len += write(f->fd, "+", 1);
		nbrlen++;
		f->precision++;
	}
	if (n == 1)
	{
		f->len += write(f->fd, "-", 1);
		nbrlen--;
		f->width--;
	}
	while (nbrlen++ < f->precision)
		f->len += write(f->fd, "0", 1);
	f->len += ft_itoa_base_pf(f->fd, nbr, 10);
	ft_padding_left_align(nbrlen, f);
}

static int	ft_decimal_right2(intmax_t nbr, int n, t_struct *f)
{
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		if (f->plus && f->width)
			f->width--;
		while (f->width)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
		if (f->plus)
			f->len += write(f->fd, "+", 1);
		return (1);
	}
	if (f->space && n == 0 && !f->width)
		f->len += write(f->fd, " ", 1);
	if (f->plus && f->zero && n == 0)
		f->len += write(f->fd, "+", 1);
	if (n == 1 && f->zero)
		f->len += write(f->fd, "-", 1);
	return (0);
}

static void	ft_print_decimal_right_align(intmax_t nbr, t_struct *f)
{
	int nbrlen;
	int n;

	nbrlen = ft_signed_nbr_len(nbr, 10);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (ft_decimal_right2(nbr, n, f))
		return ;
	if (f->plus && n == 0 && f->width && !f->precision_specified)
		nbrlen++;
	ft_padding_right_align(nbrlen, n, f);
	if (!f->zero && f->plus && n == 0)
		f->len += write(f->fd, "+", 1);
	else if (!f->zero && n == 1)
	{
		f->len += write(f->fd, "-", 1);
		nbrlen--;
	}
	f->precision = (f->width > f->precision) ? f->width : f->precision;
	while (nbrlen++ < f->precision)
		f->len += write(f->fd, "0", 1);
	f->len += ft_itoa_base_pf(f->fd, nbr, 10);
}

void		ft_print_decimal(char type, t_struct *f, va_list ap)
{
	intmax_t nbr;

	if (type == 'd' || type == 'i' || type == 'D')
	{
		if (type == 'D')
			nbr = va_arg(ap, long);
		else if (!f->length)
			nbr = va_arg(ap, int);
		else if (f->length == HH)
			nbr = (signed char)va_arg(ap, int);
		else if (f->length == H)
			nbr = (short)va_arg(ap, int);
		else if (f->length == L)
			nbr = va_arg(ap, long);
		else if (f->length == LL)
			nbr = va_arg(ap, long long);
		else if (f->length == J)
			nbr = va_arg(ap, intmax_t);
		else if (f->length == Z)
			nbr = va_arg(ap, ssize_t);
		if (f->minus)
			ft_print_decimal_left_align(nbr, f);
		else
			ft_print_decimal_right_align(nbr, f);
	}
}
