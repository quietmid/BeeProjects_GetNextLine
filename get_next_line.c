/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:16:02 by jlu               #+#    #+#             */
/*   Updated: 2023/12/01 15:33:58 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *static_buff)
{
	int		bytes;
	char	*buffer;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (NULL);

}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	
}

/*
	- Repeated calls (with loops) with get_next_line() func. It should read the text file
	pointed to by the file descriptor, one line at a time;
	- The function should return the line that was read;
	- if nothing was to be read or an error occurred, it should return NULL;
	- The function should work both in reading a file and when reading from the standard input;
	- The returned line should be include the terminating \n character, EXCEPT if the end of file was reached and does not end with a \n character;
	- all the helper functions should be in get_next_line_utils.c file;
*/