/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:16:02 by jlu               #+#    #+#             */
/*   Updated: 2023/12/05 19:04:23 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_remainder(char **str, char *nextline)
{
	char	*line;
	char	*temp_buff;

	line = NULL;
	if (*str)
	{
		nextline = ft_strchr(*str, '\n');
		if (nextline)
		{
			temp_buff = *str;
			*str = ft_strdup(nextline + 1);
			nextline = ft_memcpy(nextline, "\n\0", 2);
			line = ft_strdup(temp_buff);
			free(temp_buff);
		}
		else
		{
			line = *str;
			*str = ((void *)0);
		}
	}
	else
		line = ft_strdup("");
	return (line);
}

char	*read_line(int fd, char *line, char **static_buff, char *nextline)
{
	int		bytes;
	char	buff[BUFFER_SIZE + 1];
	char	*temp;

	bytes = 1;
	while (!nextline && bytes && line && !(*static_buff))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0 && *line == '\0')
		{
			free(line);
			return (NULL);
		}
		buff[bytes] = '\0';
		nextline = ft_strchr(buff, '\n');
		if (nextline)
		{
			*static_buff = (ft_strdup(nextline + 1));
			nextline = ft_memcpy(nextline, "\n\0", 2);
		}
		temp = line;
		line = ft_strjoin(line, buff);
		free(temp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = create_remainder(&buff, ((void *)0));
	line = read_line(fd, line, &buff, ((void *)0));
	return (line);
}
