/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 08:19:40 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 13:35:45 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE	32
# define MAX_FD		4865

int		get_next_line(const int fd, char **line);

#endif
