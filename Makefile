ifeq ($(HOSTTYPE),)
		HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
SRC = main.c show_alloc_mem.c print.c free.c region.c block.c
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
	@gcc -o $(NAME) $(OBJ) -L./libft -lft -shared
	@echo "\\033[1;32m$(NAME) was created."
	@ln -f -s libft_malloc_$(HOSTTYPE).so libft_malloc.so

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $^ -I $(HEADER)

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(CODE_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(CODE_DIR)

re: fclean all
