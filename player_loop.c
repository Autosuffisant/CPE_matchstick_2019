/*
** EPITECH PROJECT, 2020
** game loop
** File description:
** game loop of the matchstick game
*/

#include "header.h"

int player_loop(game_t *game)
{
    my_putstr("\nYour turn:\n");
    while (game->match_input > game->pick || game->match_input == 0
        || game->match_input > game->match_nbr[game->line_input]) {
        if (user_turn(game) == 1)
            return (0);
        get_matches_nbr(game);
        if (game->match_input > game->pick)
            match_max_display(game);
        if (game->match_input <= game->pick &&
                game->match_input > game->match_nbr[game->line_input])
            not_enough_match_display(game);
    }
    matches_removed_by_player_display(game);
    remove_match(game);
    get_matches_nbr(game);
    game->turn--;
    if (game->end == 0)
        return (0);
    return (1);
}

int matches_removed_by_player_display(game_t *game)
{
    my_putstr("Player removed ");
    my_put_nbr(game->match_input);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->line_input);
    my_putchar('\n');
}

int not_enough_match_display(game_t *game)
{
    my_putstr("Error: not enough matches on this line\n");
}

int match_max_display(game_t *game)
{
    my_putstr("Error: you cannot remove more than ");
    my_put_nbr(game->pick);
    my_putstr(" matches per turn\n");
}