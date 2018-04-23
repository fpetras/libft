/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:12:07 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/23 12:40:24 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	link = (t_list*)malloc(sizeof(t_list));
	if (link == NULL)
		return (NULL);
	link->next = NULL;
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
		return (link);
	}
	link->content = (t_list*)malloc(sizeof(t_list) * content_size);
	if (link->content == NULL)
	{
		free(link);
		return (NULL);
	}
	link->content = ft_memcpy(link->content, content, content_size);
	link->content_size = content_size;
	return (link);
}
