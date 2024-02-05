SRC = fractol.c fractol_helpers.c  hooks.c  hooks_julia.c  julia.c  julia_helpers_julia.c  mandelbrot.c
CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = fractol
HEADER = fractol.h
OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -L /usr/X11R6/lib -lmlx -lXext -lX11 -lm -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c $<

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
