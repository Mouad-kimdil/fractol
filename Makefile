SRC = fractol.c mandel_helpers.c  mandel_hooks.c  julia_hooks.c  julia.c  julia_helpers_julia.c  mandelbrot.c my_fractal.c my_fract_helpers.c my_fractal_hooks.c
CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = fractol
HEADER = fractol.h
OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c $<

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
