/*
** EPITECH PROJECT, 2020
** user lines input
** File description:
** all the function which checks and sets the user line input
*/

#include "./header.h"

int input_line_get(game_t *game, size_t buffersize, char *buffer)
{
    while (game->line_input <= 0 || game->line_input > game->lines) {
        game->line_input = getline(&buffer, &buffersize, stdin);
        if (input_line_check(game, buffer) == 1)
            return (1);
        if (input_line_pos_value_check(game, buffer, buffersize) == 0)
            return (0);
        if (game->line_input = stdin_getnbr(buffer, buffersize)
                                                > game->lines) {
            my_putstr("Error: this line is out of range\n");
            game->right_line = 0;
            return (0);
        }
        game->line_input = stdin_getnbr(buffer, buffersize);
    }
    game->right_line = 1;
    free(buffer);
}

int input_line_check(game_t *game, char *buffer)
{
    if (game->line_input == -1) {
        game->end = 0;
        game->abort = 1;
        free(buffer);
        return (1);
    }
    return (0);
}

int input_line_pos_value_check(game_t *game, char *buffer, size_t buffersize)
{
    if (game->line_input = stdin_getnbr(buffer, buffersize)
                                                <= 0) {
        my_putstr("Error invalid input (positive number expected)\n");
        game->right_line = 0;
        free(buffer);
        return (0);
    }
    return (1);
}