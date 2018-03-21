/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 09:33:23 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 09:48:36 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putwchar_2(wchar_t wc, t_struct *f)
{
	char wstr[4];

	wstr[0] = ((wc >> 18) + 240);
	wstr[1] = (((wc >> 12) & 63) + 128);
	wstr[2] = (((wc >> 6) & 63) + 128);
	wstr[3] = ((wc & 63) + 128);
	f->len += write(f->fd, wstr, 4);
}

void		ft_putwchar_pf(wchar_t wc, t_struct *f)
{
	char wstr[3];

	if ((wc >= 0 && wc <= 127) || (wc >= 0 && wc <= 255 && MB_CUR_MAX == 1))
		f->len += write(f->fd, &wc, 1);
	else if (wc >= 128 && wc <= 2047 && MB_CUR_MAX >= 2)
	{
		wstr[0] = ((wc >> 6) + 192);
		wstr[1] = ((wc & 63) + 128);
		f->len += write(f->fd, wstr, 2);
	}
	else if (wc >= 2048 && wc <= 65535 && MB_CUR_MAX >= 3)
	{
		wstr[0] = ((wc >> 12) + 224);
		wstr[1] = (((wc >> 6) & 63) + 128);
		wstr[2] = ((wc & 63) + 128);
		f->len += write(f->fd, wstr, 3);
	}
	else if (wc >= 65536 && wc <= 1114111 && MB_CUR_MAX == 4)
		ft_putwchar_2(wc, f);
	else
		f->len = -1;
}
