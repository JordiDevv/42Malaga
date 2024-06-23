#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    int count = 10;

    int fd = open("prueba.txt", O_RDONLY);
    char *line = get_next_line(fd);
    int size = ft_strlen(line);
    write(1, line, size);

    while (--count >= 0)
    {
        line = get_next_line(fd);
        size = ft_strlen(line);
        write(1, line, size);
    }
    return (0);
}