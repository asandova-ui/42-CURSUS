#include "get_next_line.h"

int main(void)
{
	int i = 0;
    int fd = open("archivo_prueba.txt", O_RDONLY);

	while (i < 10)
    {
        char *line = get_next_line(fd);
        if (line == NULL)
        {
            return 1;
        }
        printf("%s", line);
        free(line);
        i++;
    }
    close(fd);
    return 0;
}