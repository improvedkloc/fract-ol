NAME    = fractol

SRCS = ./utils/utils.c\
	./utils/f_events.c\
	./utils/f_init.c\
	./utils/f_rend.c\
	./fractol.c\
	
OBJS    = $(SRCS:.c=.o)

LIBC    = ar rcs
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/include/../lib -lXext -lX11 -lm -lbsd -Llibft -lft

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:    $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
