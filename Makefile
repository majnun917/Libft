CC = cc
FLAGS = 

NAME = libftprintf.a

SRC = ft_printf.c ft_arg.c ft_putchar.c ft_hexa.c ft_itoa.c  ft_uitoa.c ft_putstr.c ft_pointer.c

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $^

%.o: %.c ft_printf.h
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re