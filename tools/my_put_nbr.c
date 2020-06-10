/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../header.h"

int my_put_nbr(int n)
{
    int p = 1;
    int temp = n;
    int written = 0;

    if (n < 0)
    {
        temp *= -1;
        my_putchar('-');
    }
    while (temp / p > 9) {
        p = p  * 10;
    }
    while (p > 0) {
        written = temp / p + 48;
        temp = temp % p;
        p /= 10;
        my_putchar(written);
    }
}