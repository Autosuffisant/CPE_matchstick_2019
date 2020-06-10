/*
** EPITECH PROJECT, 2020
** user input
** File description:
** all the functions linked the the user input handling
*/

#include "header.h"

int user_turn(game_t *game)
{
    size_t buffersize = 16;
    char *buffer = malloc(sizeof(char) * buffersize);

    user_turn_set(game);
    while (game->invalid != 0) {
    my_putstr("Line: ");
    game->line_input = 0;
        if (input_line_get(game, buffersize, buffer) == 1)
        return (1);
    buffer = NULL;
    if (game->line_input > 0 && game->right_line == 1) {
        my_putstr("Matches: ");
        if (user_input_check(game, buffersize, buffer) == 1)
            return (1);
    }
    if (game->match_input > 0 && game->right_match == 1)
        game->invalid = 0;
    }
    return (0);
}

int user_turn_set(game_t *game)
{
    game->right_line = 0;
    game->right_match = 0;
    game->invalid = 1;
    return (0);
}

int user_input_check(game_t *game, size_t buffersize, char *buffer)
{
    game->match_input  = 0;
    if (input_match_get(game, buffersize, buffer) == 1)
        return (1);
    return (0);
}

int input_match_get(game_t *game, size_t buffersize, char *buffer)
{
    while (game->match_input <= 0) {
        game-> match_input = getline(&buffer, &buffersize, stdin);
        if (game->match_input == -1) {
            game->end = 0;
            game->abort = 1;
            free(buffer);
            return (1);
        }
        if (game->match_input = stdin_getnbr(buffer, buffersize)
                                                <= 0) {
            my_putstr("Error invalid input (positive number expected)\n");
            game->right_match = 0;
            free(buffer);
            return (0);
        }
        game->match_input = stdin_getnbr(buffer, buffersize);
    }
    game->right_match = 1;
    free(buffer);
}