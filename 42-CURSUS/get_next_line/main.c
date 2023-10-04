#include "get_next_line.h"

int main(void)
{
            printf("%s", "hooollalaaa");

	int i = 0;
    int fd = open("archivo_prueba.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (0);
    }
            printf("%s", "hooollalaaa");

	 while (i < 10)
    {
        printf("%s", "hooollalaaa");
        char *line = get_next_line(fd);
        if (line == NULL)
        {
			perror("Error al leer línea del archivo");
            close(fd);
            return (0);
        }
        printf("%s", line);
        free(line);
        i++;
    }
    close(fd);
    return (0);
}