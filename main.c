#include "get_next_line_utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 1;
	fd = open("oi.txt", O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		printf("linha: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}