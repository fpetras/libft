/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:48:35 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 09:45:53 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_char_left_align(unsigned char c, t_struct *f)
{
	f->len += write(f->fd, &c, 1);
	while (f->width > 1)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_print_char_right_align(unsigned char c, t_struct *f)
{
	while (f->width > 1)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
	f->len += write(f->fd, &c, 1);
}

static void	ft_print_wide_char_left_align(wchar_t wc, t_struct *f)
{
	int size;

	if (wc < 0 || wc > 1114111)
	{
		f->len = -1;
		return ;
	}
	size = (wc <= 127) ? 1 : 0;
	size = (wc >= 128 && wc <= 2047) ? 2 : size;
	size = (wc >= 2048 && wc <= 65535) ? 3 : size;
	size = (wc >= 65536 && wc <= 1114111) ? 4 : size;
	ft_putwchar_pf(wc, f);
	if (f->len == -1)
		return ;
	while (f->width > size)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_print_wide_char_right_align(wchar_t wc, t_struct *f)
{
	int size;

	if (wc < 0 || wc > 1114111)
	{
		f->len = -1;
		return ;
	}
	size = (wc <= 127) ? 1 : 0;
	size = (wc >= 128 && wc <= 2047) ? 2 : size;
	size = (wc >= 2048 && wc <= 65535) ? 3 : size;
	size = (wc >= 65536 && wc <= 1114111) ? 4 : size;
	while (f->width > size)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
	ft_putwchar_pf(wc, f);
}

void		ft_print_char(char type, t_struct *f, va_list ap)
{
	unsigned char	c;
	wchar_t			wc;

	if ((type == 'c' && f->length == L) || type == 'C')
	{
		wc = (wchar_t)va_arg(ap, wint_t);
		if (f->minus)
			ft_print_wide_char_left_align(wc, f);
		else
			ft_print_wide_char_right_align(wc, f);
	}
	else if (type == 'c')
	{
		c = (unsigned char)va_arg(ap, int);
		if (f->minus)
			ft_print_char_left_align(c, f);
		else
			ft_print_char_right_align(c, f);
	}
}
