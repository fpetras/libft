/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 07:45:42 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/23 13:51:25 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	*ft_init_struct(t_struct *f)
{
	if ((f = (t_struct*)ft_memalloc(sizeof(t_struct))) == NULL)
		return (NULL);
	f->i = 0;
	f->len = 0;
	return (f);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	int			len;
	t_struct	*f;
	va_list		ap;

	f = NULL;
	if ((f = ft_init_struct(f)) == NULL)
		return (-1);
	f->fd = fd;
	va_start(ap, format);
	if (format[0] == '%' && format[1] == '\0')
		;
	else if (!ft_strchr(format, '%'))
		f->len += write(f->fd, format, ft_strlen(format));
	else
		ft_process_string(format, f, ap);
	len = f->len;
	free(f);
	va_end(ap);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	int			len;
	t_struct	*f;
	va_list		ap;

	f = NULL;
	if ((f = ft_init_struct(f)) == NULL)
		return (-1);
	f->fd = 1;
	va_start(ap, format);
	if (format[0] == '%' && format[1] == '\0')
		;
	else if (!ft_strchr(format, '%'))
		f->len += write(f->fd, format, ft_strlen(format));
	else
		ft_process_string(format, f, ap);
	len = f->len;
	free(f);
	va_end(ap);
	return (len);
}
