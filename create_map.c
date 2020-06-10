/*
** EPITECH PROJECT, 2020
** matchstick map generator
** File description:
** generates a map with a given size of lines for the matchstick game
*/

#include "header.h"

void map_create(game_t *game, int lines)
{
    game->map = map_boundaries_set(lines);
    game->map = map_fill(game->map, lines);
    game->match_nbr = malloc(sizeof(int) * (lines+2));
    game->match_input = 0;
    game->line_input = 0;
    game->turn = 2;
    game->abort = 0;
}

char **map_fill(char **map, int lines)
{
    int len = (lines * 2) + 1;
    int center = (((lines * 2) + 1) / 2);
    int left = center;
    int right = center;

    for (int i = 0; i != (lines+2); i++) {
        for (int j = 0; j != len; j++) {
            if (j > left && j < right && map[i][j] != '*')
                map[i][j] = '|';
        }
        left--;
        right++;
    }
    return (map);
}

char **map_boundaries_set(int lines)
{
    int last_line = lines + 1;
    int len = (lines * 2) + 1;
    char **map_prototype = malloc(sizeof(char *) * (lines + 2));

    for (int i = 0; i != (last_line+1); i++) {
        map_prototype[i] = malloc(sizeof(char) * (len +1));
        map_prototype[i][len] = '\0';
    }
    for (int i = 0; i != last_line + 1; i++) {
        for (int j = 0; j != len; j++) {
            if (i == 0 || i == last_line || j == 0 || j == (len-1))
                map_prototype[i][j] = '*';
                else map_prototype[i][j] = ' ';
        }
    }
    return (map_prototype);
}