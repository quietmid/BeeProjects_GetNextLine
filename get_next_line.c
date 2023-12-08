/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:16:02 by jlu               #+#    #+#             */
/*   Updated: 2023/12/08 21:15:40 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free (*str);
	*str = NULL;
	return (NULL);
}

static char	*read_line(int fd, char *s_buff, char *buf)
{
	int		bytes;
	char	*temp_line;

	bytes = 1;
	while (!ft_strchr(buf, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		if (!s_buff)
			s_buff = ft_strdup("");
		temp_line = s_buff;
		s_buff = ft_strjoin(temp_line, buf);
		if (!s_buff)
			return (ft_free(&temp_line));
		ft_free(&temp_line);
	}
	return (s_buff);
}

static char	*get_line(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!temp)
		return (ft_free(&line));
	if (temp[0] == '\0')
		return (ft_free(&temp));
	return (temp);
}

static char	*fix_line(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	result = ft_substr(line, 0, i + 1);
	if (!result)
		return (ft_free(&line));
	free (line);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	char		*result;

	line = NULL;
	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, buff, buf);
	if (!line)
		return (ft_free(&buff));
	buff = get_line(line);
	result = fix_line(line);
	if (!result)
		return (ft_free(&buff));
	return (result);
}

//#include <fcntl.h>
//#include <stdio.h>

//int	main(void)
//{
//	int	fd;
//	char	*line;
//	int	i;

//	fd = open("multiple_nl.txt", O_RDONLY);

//	if (fd == -1)
//	{
//		perror("Error opening file");
//		return (1);
//	}
//	i = 0;
//	while ((line = get_next_line(fd)) != NULL)
//	{
//		printf("%s", line);
//		free(line);
//	}
//	close(fd);
//	return 0;
//}