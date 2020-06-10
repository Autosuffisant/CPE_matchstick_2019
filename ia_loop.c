/*
** EPITECH PROJECT, 2020
** IA loop
** File description:
** all the loop functions related to the IA of the matchstick game
*/

#include "./header.h"

int ia_loop(game_t *game)
{
    get_matches_nbr(game);
    ia_match_check(game);
    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(game->ia_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->ia_line);
    my_putchar('\n');
    ia_remove_match(game);
    get_matches_nbr(game);
    game->turn++;
    return (1);
}

int ia_match_check(game_t *game)
{
    game->ia_match = 0;
    game->ia_line = 1;
    for (; game->match_nbr[game->ia_line] <= 1
        && game->ia_line < game->lines+1;
        game->ia_line++);
    if (game->ia_line > game->lines)
        ia_single_match_check(game);
    if (game->match_nbr[game->ia_line] > game->pick)
        game->ia_match = game->pick;
        else game->ia_match = game->match_nbr[game->ia_line] - 1;
    if (game->ia_match <= 0)
        game->ia_match = 1;
}

int ia_single_match_check(game_t *game)
{
    game->ia_line = 1;
    for (; game->match_nbr[game->ia_line] != 1; game->ia_line++);
}

int ia_remove_match(game_t *game)
{
    int len = (game->lines * 2) + 1;

    if (game->end == 0)
        return (0);
    for (int j = len; j != 0; j--)
        if (game->map[game->ia_line][j] == '|' && game->ia_match != 0) {
            game->map[game->ia_line][j] = ' ';
            game->ia_match--;
        }
    return (0);
}