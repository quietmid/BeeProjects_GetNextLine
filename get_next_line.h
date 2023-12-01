/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:16:13 by jlu               #+#    #+#             */
/*   Updated: 2023/12/01 15:33:59 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);

# endif