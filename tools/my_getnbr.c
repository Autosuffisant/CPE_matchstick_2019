/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** task 05
*/

#include "../header.h"

int	stdin_getnbr(char const *str, size_t buffersize)
{
    int i = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        if ((str[j] < '0' || str[j] > '9') && str[j] != '\n')
            return (0);
    }
    i = my_getnbr(str);
    return (i);
}

int my_getnbr(char const *str)
{
    int s = 1;
    int r = 0;
    int i = 0;

    if (str == 0)
        return (0);
    while ((*str < 47 || *str > 58) && *str != 0) {
        str = str + 1;
        i++;
    }
    if (i > 0 && *(str - 1) == 45)
        s = -1;
    while (*str != 0 && *str >= '0' && *str <= '9') {
        r = r * 10;
        r = r + *str - 48;
        str = str + 1;
    }
    r = r * s;
    return (r);
}