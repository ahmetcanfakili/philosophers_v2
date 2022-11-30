NAME = philo

SRC		= ft_init.c ft_routine.c ft_utils.c philosophers.c

OBJ		= $(SRC:.c=.o)

OBJ_DIR	= obj/

SRC_DIR	= ./

OBJ_SRC		= $(addprefix $(OBJ_DIR), $(OBJ))

SRC_FILES	= $(addprefix $(SRC_DIR), $(SRC))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME) 
	@echo "\033[32mCompilation done\033[0;39m"

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) 2> /dev/null
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIR)

re:	fclean all

.PHONE: all clean fclean re