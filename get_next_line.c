/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:56:54 by fkonig            #+#    #+#             */
/*   Updated: 2024/12/20 16:34:53 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

static char	*reader(int fd, char *buffer, char *line)
{
	int		byt;
	char	*buff;

	byt = 1;
	while (byt >= 1 && !(ft_strchr(line, '\n')))
	{
		byt = read (fd, buffer, BUFFER_SIZE);
		if (byt == -1)
			return (free(line), buffer[0] = '\0', NULL);
		buffer[byt] = '\0';
		buff = ft_strjoin(line, buffer);
		free(line);
		if (!buff)
			return (NULL);
		line = buff;
		if (line == NULL || ft_strlen(line) == 0)
			return (free(line), NULL);
	}
	return (line);
}

static char	*remaining(char *buffer, char *line)
{
	size_t	line_length;
	char	*nextl;
	char	*temp;

	nextl = ft_strchr(line, '\n');
	buffer[0] = '\0';
	temp = NULL;
	line_length = 0;
	if (nextl)
	{
		line_length = nextl - line + 1;
		ft_strlcpy(buffer, nextl + 1, BUFFER_SIZE + 1);
		nextl[1] = '\0';
		temp = ft_strdup(line);
		free(line);
		return (temp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	line = reader(fd, buffer, line);
	if (!line)
		return (free(line), NULL);
	return (remaining(buffer, line));
}

// #include <fcntl.h>

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	fd = open("testfile.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 		printf("$\n");
// 	close(fd);
// }
