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
	if(buffer[i] != '\n')
	{
		i++;
		buffer[i] = '\n';
	}
}

getnextline
get file and read line by line 
fd 
 a = strsearch: if nl 
	strcut till nl
	rest in static char*
else 
	strlen
	malloc str
	reread with buffer
	a 
	strjoin bis newline
return str
