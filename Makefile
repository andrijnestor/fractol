# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 13:19:27 by anestor           #+#    #+#              #
#    Updated: 2018/01/31 21:59:06 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror
EXT = fractol.h

SRC =
SRC += main.c
SRC += image_xpm.c
SRC += image.c
SRC += colors.c
SRC += mandelbrot.c
SRC += julia.c
SRC += key_hooks.c


OBJ        = $(patsubst %.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ) $(EXT)
	@make -C libft/
	@gcc $(FLAGS) -L libft/ -lft -L/usr/local/lib -lmlx -lpthread -framework OpenGL -framework AppKit obj/*.o -o $(NAME) -g

obj/%.o: %.c $(EXT)
	@mkdir -p obj
	@gcc $(FLAGS) -c $< -o $@ -g
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
