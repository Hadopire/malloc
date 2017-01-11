# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncharret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 19:16:41 by ncharret          #+#    #+#              #
#    Updated: 2017/01/11 18:44:44 by ncharret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = malloc
SRC = main.c show_alloc_mem.c print.c free.c
OBJ = $(SRC:.c=.o)
HEADER = ./libft/
CODE_DIR = libft/
FLAGS = -Wall -Werror -Wextra

.PHONY: libft.a

all: $(NAME)

libft.a:
	@$(MAKE) -C $(CODE_DIR)

$(NAME): $(OBJ)
	@$(MAKE) -C $(CODE_DIR)
	@gcc -o $(NAME) $(OBJ) -L./libft -lft
	@echo "\\033[1;32m$(NAME) was created."

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $^ -I $(HEADER)

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(CODE_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(CODE_DIR)

re: fclean all
