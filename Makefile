NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
