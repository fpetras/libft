/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_control_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 07:39:43 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 09:46:08 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_non_printable3(unsigned char c, t_struct *f)
{
	if (c == 22)
		f->len += write(f->fd, "^V", 2);
	else if (c == 23)
		f->len += write(f->fd, "^W", 2);
	else if (c == 24)
		f->len += write(f->fd, "^X", 2);
	else if (c == 25)
		f->len += write(f->fd, "^Y", 2);
	else if (c == 26)
		f->len += write(f->fd, "^Z", 2);
	else if (c == 27)
		f->len += write(f->fd, "^[", 2);
	else if (c == 28)
		f->len += write(f->fd, "^\\", 2);
	else if (c == 29)
		f->len += write(f->fd, "^]", 2);
	else if (c == 30)
		f->len += write(f->fd, "^^", 2);
	else if (c == 31)
		f->len += write(f->fd, "^_", 2);
	else if (c == 127)
		f->len += write(f->fd, "^?", 2);
}

static void	ft_print_non_printable2(unsigned char c, t_struct *f)
{
	if (c == 11)
		f->len += write(f->fd, "^K", 2);
	else if (c == 12)
		f->len += write(f->fd, "^L", 2);
	else if (c == 13)
		f->len += write(f->fd, "^M", 2);
	else if (c == 14)
		f->len += write(f->fd, "^N", 2);
	else if (c == 15)
		f->len += write(f->fd, "^O", 2);
	else if (c == 16)
		f->len += write(f->fd, "^P", 2);
	else if (c == 17)
		f->len += write(f->fd, "^Q", 2);
	else if (c == 18)
		f->len += write(f->fd, "^R", 2);
	else if (c == 19)
		f->len += write(f->fd, "^S", 2);
	else if (c == 20)
		f->len += write(f->fd, "^T", 2);
	else if (c == 22)
		f->len += write(f->fd, "^U", 2);
	else
		ft_print_non_printable3(c, f);
}

static void	ft_print_non_printable(unsigned char c, t_struct *f)
{
	if (c == 0)
		f->len += write(f->fd, "^@", 2);
	else if (c == 1)
		f->len += write(f->fd, "^A", 2);
	else if (c == 2)
		f->len += write(f->fd, "^B", 2);
	else if (c == 3)
		f->len += write(f->fd, "^C", 2);
	else if (c == 4)
		f->len += write(f->fd, "^D", 2);
	else if (c == 5)
		f->len += write(f->fd, "^E", 2);
	else if (c == 6)
		f->len += write(f->fd, "^F", 2);
	else if (c == 7)
		f->len += write(f->fd, "^G", 2);
	else if (c == 8)
		f->len += write(f->fd, "^H", 2);
	else if (c == 9)
		f->len += write(f->fd, "^I", 2);
	else if (c == 10)
		f->len += write(f->fd, "^J", 2);
	else
		ft_print_non_printable2(c, f);
}

static void	ft_print_control_char2(unsigned char c, t_struct *f)
{
	if (f->minus)
	{
		ft_print_non_printable(c, f);
		while (f->width > 2)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
	}
	else
	{
		while (f->width > 2)
		{
			if (f->zero)
				f->len += write(f->fd, "0", 1);
			else
				f->len += write(f->fd, " ", 1);
			f->width--;
		}
		ft_print_non_printable(c, f);
	}
}

void		ft_print_control_char(char type, t_struct *f, va_list ap)
{
	unsigned char	c;

	if (type == 'r')
	{
		c = (unsigned char)va_arg(ap, int);
		ft_print_control_char2(c, f);
	}
}
