/*
** EPITECH PROJECT, 2020
** pick matches
** File description:
** functions dedicated to the picking of matches in the matchstick game
*/

#include "./header.h"

int get_matches_nbr(game_t *game)
{
    int len = (game->lines * 2) + 1;

    game->end = 0;
    for (int i = 0; i != game->lines +2; i++) {
        game->match_nbr[i] = 0;
        for (int j = 0; j != len; j++)
            if (game->map[i][j] == '|')
                game->match_nbr[i]++;
    }
    for (int i = 0; i != game->lines +2; i++) {
        game->end += game->match_nbr[i];
    }
}

int remove_match(game_t *game)
{
    int len = (game->lines * 2) + 1;

    if (game->end == 0)
        return (0);
    for (int j = len; j != 0; j--)
        if (game->map[game->line_input][j] == '|' && game->match_input != 0) {
            game->map[game->line_input][j] = ' ';
            game->match_input--;
        }
    game->match_input = 0;
    return (0);
}