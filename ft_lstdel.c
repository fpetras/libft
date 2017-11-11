/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:26:30 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/10 18:26:17 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *link;
	t_list *tmp;

	if (!(*alst))
		return ;
	link = *alst;
	while (link != NULL)
	{
		tmp = link->next;
		del(link, link->content_size);
		link = tmp;
	}
	*alst = NULL;
}
