/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 08:47:47 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 09:46:32 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_string_left_align(char *str, t_struct *f)
{
	int strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->precision_specified && strlen > 0 && strlen > f->precision)
		strlen = f->precision;
	f->len += write(f->fd, str, strlen);
	while (f->width > strlen)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_print_string_right_align(char *str, t_struct *f)
{
	int strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->precision_specified && strlen > 0 && strlen > f->precision)
		strlen = f->precision;
	while (f->width > strlen)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
	f->len += write(f->fd, str, strlen);
}

static void	ft_print_wide_string_left_align(wchar_t *wstr, t_struct *f)
{
	int wstrsize;

	if (!wstr)
		wstr = L"(null)";
	wstrsize = ft_wstrsize_pf(wstr);
	if (f->precision_specified && wstrsize > 0 && wstrsize > f->precision)
		wstrsize = f->precision;
	ft_putwstr_pf(wstr, f, wstrsize);
	if (f->len == -1)
		return ;
	while (f->width > wstrsize)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_print_wide_string_right_align(wchar_t *wstr, t_struct *f)
{
	int wstrsize;

	if (!wstr)
		wstr = L"(null)";
	wstrsize = ft_wstrsize_pf(wstr);
	if (f->precision_specified && wstrsize > 0 && wstrsize > f->precision)
		wstrsize = f->precision;
	ft_check_mb_cur_max(wstr, f);
	if (f->len == -1)
		return ;
	while (f->width > wstrsize)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
	ft_putwstr_pf(wstr, f, wstrsize);
}

void		ft_print_string(char type, t_struct *f, va_list ap)
{
	char	*str;
	wchar_t	*wstr;

	if ((type == 's' && f->length == L) || type == 'S')
	{
		wstr = va_arg(ap, wchar_t *);
		if (f->minus)
			ft_print_wide_string_left_align(wstr, f);
		else
			ft_print_wide_string_right_align(wstr, f);
	}
	else if (type == 's')
	{
		str = va_arg(ap, char *);
		if (f->minus)
			ft_print_string_left_align(str, f);
		else
			ft_print_string_right_align(str, f);
	}
}
