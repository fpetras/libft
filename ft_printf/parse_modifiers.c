/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:18:34 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/09 16:32:06 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_length(const char *format, t_struct *f)
{
	if (ft_strchr("hljz", format[f->i]))
	{
		if (format[f->i] == 'h')
		{
			if (format[f->i + 1] == 'h')
				f->length = HH;
			else
				f->length = H;
		}
		else if (format[f->i] == 'l')
		{
			if (format[f->i + 1] == 'l')
				f->length = LL;
			else
				f->length = L;
		}
		else if (format[f->i] == 'j')
			f->length = J;
		else if (format[f->i] == 'z')
			f->length = Z;
		while (ft_strchr("hljz", format[f->i]))
			f->i++;
	}
}

static void	ft_precision(const char *format, t_struct *f, va_list ap)
{
	int precision;

	if (format[f->i] == '.')
	{
		f->i++;
		f->precision_specified = 1;
		if (ft_isdigit(format[f->i]))
		{
			f->precision = ft_atoi(&format[f->i]);
			while (ft_isdigit(format[f->i]))
				f->i++;
		}
		else if (format[f->i] == '*')
		{
			precision = va_arg(ap, int);
			if (precision >= 0)
				f->precision = precision;
			else
				f->precision_specified = 0;
			while (format[f->i] == '*')
				f->i++;
		}
	}
	if (f->precision_specified && !f->minus)
		f->space = 0;
}

static void	ft_width(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		f->minus = (f->width < 0) ? 1 : f->minus;
		f->width = (f->width < 0) ? -f->width : f->width;
		while (format[f->i] == '*')
			f->i++;
	}
	if (ft_isdigit(format[f->i]))
	{
		f->width = ft_atoi(&format[f->i]);
		while (ft_isdigit(format[f->i]))
		{
			f->i++;
			if (format[f->i] == '*')
			{
				f->width = va_arg(ap, int);
				f->width = (f->width < 0) ? -f->width : f->width;
				while (format[f->i] == '*')
					f->i++;
			}
		}
	}
}

static void	ft_flags(const char *format, t_struct *f)
{
	while (ft_strchr("-+ 0#", format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		else if (format[f->i] == '+')
			f->plus = 1;
		else if (format[f->i] == ' ')
			f->space = 1;
		else if (format[f->i] == '0')
			f->zero = 1;
		else if (format[f->i] == '#')
			f->hash = 1;
		f->i++;
	}
	if (f->plus)
		f->space = 0;
}

void		ft_parse_modifiers(const char *format, t_struct *f, va_list ap)
{
	ft_flags(format, f);
	ft_width(format, f, ap);
	ft_precision(format, f, ap);
	ft_length(format, f);
}
