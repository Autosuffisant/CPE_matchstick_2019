/*
** EPITECH PROJECT, 2020
** display map
** File description:
** displays the map for the matchstick
*/

#include "header.h"

void map_display(game_t *game)
{
    for (int i = 0; i != (game->lines+2); i++) {
        my_putstr(game->map[i]);
        my_putchar('\n');
    }
}