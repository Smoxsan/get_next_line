#include <stdio.h>

char *get_next_line(int fd)
{
	char buffer[300];
	int i;
	int read_bytes;

	while (buffer[i] != '\0')
	{
		read_bytes = read(fd, buffer, 300);
		ft_printf("%c", buffer[i]);
		i++;
	}
}