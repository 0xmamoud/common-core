#include "libft/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line = NULL;

    fd = open("testfile.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open file\n");
        return (1);
    }
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	printf("%s", line);
    close(fd);
    return (0);
}