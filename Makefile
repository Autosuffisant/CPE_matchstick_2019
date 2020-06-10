##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## matchstick Makefile
##

NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
		  ./tools/my_putstr.c \
		  ./tools/my_getnbr.c \
		  ./tools/my_put_nbr.c \
		  ./create_map.c \
		  ./display_map.c \
		  ./game_loop.c \
		  ./player_loop.c \
		  ./ia_loop.c \
		  ./user_input.c \
		  ./user_lines_input.c \
		  ./pick_matches.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re