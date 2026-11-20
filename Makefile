NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I .

SRC = ft_printf.c ft_printf_conv1.c ft_printf_conv2.c

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