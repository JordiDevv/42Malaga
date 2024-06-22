#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    int fd = open("prueba.txt", O_RDONLY);
    char *line = get_next_line(fd);
    int size = sizeof(line);
    write(1, line, size);

    return (0);
}