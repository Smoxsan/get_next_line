/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:56:54 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/25 16:00:02 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>  // For non-blocking file descriptor flags

static char	*reader(int fd, char *buffer, char *line)
{
	int	byt;

	byt = 1;
	while (byt >= 1 && !(ft_strchr(line, '\n')))
	{
		byt = read (fd, buffer, BUFFER_SIZE);
		if (byt == -1)
			return (free(line), buffer[0] = '\0', NULL);
		buffer[byt] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strlen(line) == 0)
			return (free(line), NULL);
	}
	return (line);
}

static char	*remaining(char *nl, char *l, char *buffer)
{
	size_t	line_length;

	nl = ft_strchr(l, '\n');
	if (nl)
	{
		line_length = nl - l + 1;
		ft_strlcpy(buffer, nl + 1, BUFFER_SIZE + 1);
	}
	else
	{
		line_length = ft_strlen(l);
		buffer[0] = '\0';
	}
	l[line_length] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*nextl;
	char		*line;

	nextl = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer);
	if (!line)
		return (free(line), NULL);
	line = reader(fd, buffer, line);
	if (!line)
		return (NULL);
	remaining(nextl, line, buffer);
	return (line);
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

// 	s = ft_strndup(b, i);
// 	if(!s)
// 		return(free(s), s = NULL);
// 	e = ft_strrchr(buffer, '\n');
// 	while(e == 0)
// 	{
// 		reader(fd, b, s);
// 	}
// 	i = e - buffer;
// }

// char *t;
// static char buffer;
// int count;

// count = 0;
	// strjoin(c, t);
	// while (buffer[i] != '\0')
	// {
	// 	read_bytes = read(fd, buffer, 300);
	// 	ft_printf("%c", buffer[i]);
	// 	i++;
	// }
	// if(buffer[i] != '\n')
	// {
	// 	i++;
	// 	buffer[i] = '\n';
	// }
// int ex_newline(static char buffer[BUFFER_SIZE], int fd, char *b)
// {
// 	int i;
// 	char *s;
// 	char *e;

// 	i = 0;
// 	s = ft_strndup(b, i);
// 	e = ft_strrchr(buffer, '\n');
// 	while(e == 0)
// 	{
// 		reader
// 	}
// 	i = e - buffer;

// 	return(s);
// }
	// if(e = ft_strrchr(buffer, '\n'))
	// 	return()
	// while()
	// {
	// 	buffer = read(fd, buffer, BUFFER_SIZE)
	// 	i++;
	// }
	// s = buffer[0];
	// e = ft_strrchr(buffer, '\n');