/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:06:19 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 09:44:45 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_pointer_left_align(intmax_t nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16) + 2;
	f->len += write(f->fd, "0x", 2);
	if (nbr == 0 && f->precision_specified && !f->precision)
		return ;
	while (f->precision > (nbrlen - 2))
	{
		f->len += write(f->fd, "0", 1);
		f->precision--;
	}
	f->len += ft_uitoa_base_pf(f->fd, nbr, 16, 0);
	while (f->width > nbrlen)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_print_pointer_right_align(uintmax_t nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16) + 2;
	while (f->width > nbrlen)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
	f->len += write(f->fd, "0x", 2);
	if (nbr == 0 && f->precision_specified && !f->precision)
		return ;
	while ((nbrlen - 2) < f->precision)
	{
		f->len += write(f->fd, "0", 1);
		nbrlen++;
	}
	f->len += ft_uitoa_base_pf(f->fd, nbr, 16, 0);
}

void		ft_print_pointer(char type, t_struct *f, va_list ap)
{
	uintmax_t nbr;

	if (type == 'p')
		nbr = (long long)va_arg(ap, void *);
	if (f->minus)
		ft_print_pointer_left_align(nbr, f);
	else
		ft_print_pointer_right_align(nbr, f);
}
