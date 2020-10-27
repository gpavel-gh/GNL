NAME = GNL_Program

NAMELIB = libGNT.a

CC = gcc

WFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c main.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

lib: $(NAMELIB)

$(NAMELIB): $(OBJ)
	ar rc $(NAMELIB) $(OBJ)
	ranlib $(NAMELIB)

all: $(NAME)

$(NAME): $(src)
	$(CC) -g3 $(WFLAGS) -D BUFFER_SIZE=1 $(SRC)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME) $(NAMELIB)

re: fclean clean all

.PHONY: clean fclean all res
