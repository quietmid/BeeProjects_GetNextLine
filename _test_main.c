#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;
	int	i;

	fd = open("multiple_nl.txt", O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d%s", i++, line);
		free(line);
	}
	close(fd);
	return 0;
}