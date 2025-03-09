CC = cc

CFLAGS = -Wall -Wextra -Werror

Header = so_long.h

SRC_FILES = main.c \
			play.c \
			name_check.c \
			map_check.c \
			helper/walls_check.c \
			helper/draw_map.c \
			helper/flood_fill.c \
			helper/free.c \
			helper/ft_strlen.c \
			helper/ft_strrchr.c \
			helper/image_to_ptr.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = so_long

libmlx = minilibx-linux/libmlx_Linux.a

PRINTF = printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(PRINTF) $(libmlx) $(Header)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(PRINTF) $(libmlx) -lXext -lX11 -lm -o $(NAME)

$(libmlx):
	$(MAKE) -C minilibx-linux

$(PRINTF):
	$(MAKE) -C printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	$(MAKE) -C printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C printf fclean

re: fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJ_FILES)