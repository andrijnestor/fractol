# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 13:41:32 by anestor           #+#    #+#              #
#    Updated: 2018/02/04 18:09:53 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_thpool.a
FLAGS = 
ODIR = bin/
OBJ = $(SRC:.c=.o)
EXT = ft_thpool.h
SRC = 

SRC += tp_create.c
SRC += tp_signal.c
SRC += tp_wait_for_signal.c
SRC += tp_exec_queue_add.c
SRC += tp_wait_for_queue.c

O = $(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O) $(EXT)
#	@echo " ░       \033[96mcompiling libft\033[0m       ░ "
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(ODIR)%.o: %.c $(EXT)
	@echo "... compiling $< ..."
	@gcc $(FLAGS) -c $< -o $@

$(O): | ./bin

./bin:
	@mkdir $(ODIR)

clean:
	@echo "... cleaning libft obj ..."
	@rm -f bin/*.o

fclean: clean
	@echo "... cleaning $(NAME) ..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
