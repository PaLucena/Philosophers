NAME = philo

CC = gcc
FLAGS = -g -Wall -Wextra -Werror
A =  -fsanitize=thread -g3
RM = rm -rf

SRC_PATH = src/
SRC = cycle.c init.c main.c philo.c utils.c
OBJ_PATH = objs/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ gcc $(FLAGS) $(OBJ) -o $(NAME)
	@ echo "\n\t\t$(GREEN)$(BOLD)----Philosophers compiled----\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ mkdir -p  $(OBJ_PATH)
	@ $(CC) $(FLAGS) -c $< -o $@

clean:
	@ $(RM) -r $(OBJ_PATH)
	@ echo "\n\t\t\t$(RED)$(BOLD)Cleaning...\n$(RESET)"

fclean: clean
	@ $(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re