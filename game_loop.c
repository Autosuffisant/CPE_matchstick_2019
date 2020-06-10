/*
** EPITECH PROJECT, 2020
** game_loop
** File description:
** game_loop function of the matchstick
*/

#include "./header.h"

int game_loop(game_t *game)
{
    if (player_loop(game) == 0) {
        if (game->abort == 1)
            return (0);
        map_display(game);
        return (0);
    }
    map_display(game);
    if (ia_loop(game) == 0) {
        map_display(game);
        return (0);
    }
    map_display(game);
    return (1);
}