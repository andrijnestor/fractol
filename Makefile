# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 13:19:27 by anestor           #+#    #+#              #
#    Updated: 2018/02/07 21:53:26 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror -O3
EXT = fractol.h

SRC =
SRC += main.c
SRC += image.c
SRC += mandelbrot.c
SRC += julia.c
SRC += key_hooks.c
SRC += mouse_hooks.c
SRC += render.c


OBJ        = $(patsubst %.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ) $(EXT)
	@make -C libft/
	@gcc $(FLAGS) -l pthread -L libft/ -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit obj/*.o -o $(NAME)

obj/%.o: %.c $(EXT)
	@mkdir -p obj
	@gcc $(FLAGS)  -c $< -o $@
	@echo "... compiling $< ..."

clean:
	@/bin/rm -rf obj/
	@make -C libft/ clean
	@echo "... cleaning fdf obj ..."

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@echo "... cleaning $(NAME) ..."

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all test
