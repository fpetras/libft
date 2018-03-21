/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 08:34:24 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/14 07:48:20 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	next_line(char *str, char **line)
{
	size_t	i;
	char	*next_line;

	i = ft_strcspn(str, "\n");
	next_line = ft_strnew(i);
	ft_memcpy(next_line, str, i);
	line[0] = next_line;
}

static char	*remaining_lines(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			return (&str[i]);
		}
		i++;
	}
	return (&str[i]);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	static char		*file[MAX_FD];

	if (fd < 0 || fd > MAX_FD || !line)
		return (-1);
	if (!file[fd])
	{
		file[fd] = ft_strnew(0);
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			tmp = file[fd];
			file[fd] = ft_strjoin(tmp, buf);
			ft_strdel(&tmp);
		}
		if (ret == -1)
			return (-1);
	}
	if (file[fd][0] == '\0')
		return (0);
	next_line(file[fd], line);
	file[fd] = remaining_lines(file[fd]);
	return (1);
}
