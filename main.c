/*
** EPITECH PROJECT, 2020
** main
** File description:
** matchstick main file
*/

#include "header.h"

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    int end;

    if (arguments_handling(ac, av, game) == 84)
        return (84);
    map_set(game);
    while (game->end != 0) {
        game_loop(game);
    }
    end = (((game->turn) % 2) + 1);
    if (game->abort == 0)
        end_display(game);
    if (game->abort == 1) {
        all_memory_free(game);
        return (0);
    }
    all_memory_free(game);
    return (end);
}

void map_set(game_t *game)
{
    map_create(game, game->lines);
    map_display(game);
    get_matches_nbr(game);
}

void all_memory_free(game_t *game)
{
    for (int i = 0; i != (game->lines + 2); i++)
        free(game->map[i]);
    free(game->map);
    free(game->match_nbr);
    free(game);
}

void end_display(game_t *game)
{
    if (game->turn == 2)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    if (game->turn == 1)
        my_putstr("You lost, too bad...\n");
}

int arguments_handling(int ac, char **av, game_t *game)
{
    if (ac != 3) {
        free(game);
        return (84);
    }
    game->lines = stdin_getnbr(av[1], 2);
    game->pick = stdin_getnbr(av[2], 2);
    if (game->lines >= 100 || game->lines <= 1)
        return (84);
    if (game->lines == 0 || game->pick == 0)
        return (84);
    return (0);
}