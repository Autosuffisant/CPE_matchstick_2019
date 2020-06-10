/*
** EPITECH PROJECT, 2020
** header
** File description:
** matchstick header
*/

#ifndef MATCHSTICK_
#define MATCHSTICK_
#define _GNU_SOURCE

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct game_s
{
    char **map;
    int *match_nbr;
    int lines;
    int pick;
    int line_input;
    int match_input;
    int ia_line;
    int ia_match;
    int turn;
    int state;
    int end;
    int abort;
    int invalid;
    int right_line;
    int right_match;
} game_t;

int main(int ac, char **av);
int arguments_handling(int ac, char **av, game_t *game);
int my_putchar(char c);
int my_putstr(char const *str);
int	stdin_getnbr(char const *str, size_t buffersize);
int my_getnbr(char const *str);
int my_put_nbr(int n);
void map_set(game_t *game);
void map_create(game_t *game, int lines);
char **map_boundaries_set(int lines);
char **map_fill(char **map, int lines);
int *set_match_numbers(int *nbr, int lines);
int game_loop(game_t *game);
int player_loop(game_t *game);
int ia_loop(game_t *game);
int ia_match_check(game_t *game);
int ia_single_match_check(game_t *game);
int ia_remove_match(game_t *game);
int user_turn(game_t *game);
int user_turn_set(game_t *game);
int user_input_check(game_t *game, size_t buffersize, char *buffer);
int input_line_get(game_t *game, size_t buffersize, char *buffer);
int input_line_check(game_t *game, char *buffer);
int input_line_pos_value_check(game_t *game, char *buffer, size_t buffersize);
int input_match_get(game_t *game, size_t buffersize, char *buffer);
int get_matches_nbr(game_t *game);
int not_enough_match_display(game_t *game);
int match_max_display(game_t *game);
int matches_removed_by_player_display(game_t *game);
int remove_match(game_t *game);
int check_exit(char *buffer);
void all_memory_free(game_t *game);
void end_display(game_t *game);
void map_display(game_t *game);


#endif /* !MATCHSTICK_ */