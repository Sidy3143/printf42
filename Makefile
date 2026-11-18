NAME = libftprint.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I .

SRC = ft_printf.c ft_printf_conversions.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean	all

.PHONY: all clean fclean re