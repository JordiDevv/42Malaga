#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int count = 10;
    int fd = open("prueba.txt", O_RDONLY);
    int fdb = open("prueba_bonus.txt", O_RDONLY);
    int fdb2 = open("prueba2_bonus.txt", O_RDONLY);
    char *line;
    int size;
    if (argc > 1 && !strcmp("bonus", argv[1]))
    {
        int file = 1;

        while (--count >= 0)
        {
            if (file == 1)
            {
                line = get_next_line(fdb);
                file++;
            }
            else
            {
                line = get_next_line(fdb2);
                file--;
            }
            size = ft_strlen(line);
            write(1, line, size);
        }
    }
    else
    {
        while (--count >= 0)
        {
            line = get_next_line(fd);
            size = ft_strlen(line);
            write(1, line, size);
        }
    }
    close(fd);
    close(fdb);
    close(fdb2);
    return (0);
}
