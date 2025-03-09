CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c \
		ft_strchr.c \
		print_char.c \
		print_hex.c \
		print_int.c \
		print_pointer.c \
		print_same.c \
		print_str.c \
		print_unsigned.c


OBJ = $(SRCS:.c=.o)

AR = ar rcs
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all