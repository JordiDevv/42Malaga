#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
    int i;
    int sign;
    int n;

    i = 0;
    sign = 0;
    n = 0;
    while (str[i] > 9 && str[i] < 14 || str[i] == 32)
        i++;
    if (str[i] == '-')
        sign = 1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] < '0' || str[i] > '9')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        n *= 10;
        n += str[i] - 48;
        i++;
    }
    if (sign)
        n *= -1;
    return (n);
}

void construct_lane(int first_lanes, int total_space, int j)
{
    int i;
    int space;

    i = first_lanes;
    while(i--)
        write(1, " ", 1);
    i = 2 * j;
    while (i--)
        write(1, "*", 1);
    space = total_space;
    while (space--)
        write (1, " ", 1);
    i = 2 * j;
    while(i--)
        write(1, "*", 1);
    i = first_lanes;
    while (i--)
        write(1, " ", 1);
}

void construct_first_half(int n)
{
    int first_lanes;
    int total_space;
    int lane_multiplier;

    first_lanes = n - 1;
    total_space = 1 + 2 * (n - 2);
    lane_multiplier = 1;
    while (first_lanes)
    {
        construct_lane(first_lanes, total_space, lane_multiplier);
        first_lanes--;
        lane_multiplier++;
        total_space -= 2;
        write(1, "\n", 1);
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 1 || !argv[1][0])
    {
        write(1, "Error: No arguments given\n", 26);
        return (0);
    }
    while (argv[1][i])
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            write(1, "Error: Arguments are not correct\n", 34);
            return (0);
        }
        i++;
    }
    if (ft_atoi(argv[1]) <= 0)
        return (0);
    construct_first_half(ft_atoi(argv[1]));
    //construct_second_half();
    return (0);
}