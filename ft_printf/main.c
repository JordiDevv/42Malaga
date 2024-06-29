#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>

int main()
{
    char c = 'c';
    void *p = &c;
    void *nil_ptr;
    char *str = {0};

    printf("NIVEL 1\nEste es el printf original:\n");
    int o = printf("%c %s %p %d %i %u %x %X %%", 'c', "Hola", p, 2, 3, 4, 16, 42);
    printf(" || %d\nEste es el mío:\n", o);
    int m = ft_printf("%c %s %p %d %i %u %x %X %%", 'c', "Hola", p, 2, 3, 4, 16, 42);
    printf(" || %d\n", m);

    printf("\nCREISICURA\n");

    printf("Este es el printf original:\n");
    int o2 = printf("%c %s %p %d %i %u %x %X %%", 23, str, nil_ptr, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648);
    printf(" || %d\nEste es el mío:\n", o2);
    int m2 = ft_printf("%c %s %p %d %i %u %x %X %%", 23, str, nil_ptr, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648);
    printf(" || %d\n", m2);

    printf("\nLA PRUEBA DE FUEGO\n");
    
    printf("Este es el printf original:\n");
    int o3 = printf("%k %kd %tk % %tkd %tkd %", 3, 3, 3, 3, 3, 3, 3);
    printf(" || %d\nEste es el mío:\n", o3);
    int m3 = ft_printf("%k %kd %tk % %tkd %tkd %", 3, 3, 3, 3, 3, 3, 3);
    printf(" || %d\n", m3);

    return 0;
}