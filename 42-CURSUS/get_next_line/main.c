#include "get_next_line.h"

int main(void)
{
	int i = 0;
    int fd = open("archivo_prueba.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
	 while (i < 100)
    {
        char *line = get_next_line(fd);
        if (line == NULL)
        {
			perror("Error al leer línea del archivo");
            close(fd);
            return 1;
        }
        printf("%s ", line);
        free(line);
        i++;
    }
    close(fd);
    return 0;
}