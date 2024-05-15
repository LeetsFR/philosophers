NAME = libft.a
CC = cc -Wall -Wextra -Werror 

SRC_FILE = ft_strlen.c ft_strlen_until.c ft_arrlen.c ft_atol.c ft_atoul.c ft_count_words.c ft_split.c ft_free_arr.c ft_strdup.c ft_strjoin.c ft_strcmp.c ft_strchr.c ft_strndup.c ft_error.c ft_arrcpy.c ft_arrdup.c ft_print_arr.c ft_isalpha.c ft_isalnum.c ft_strncmp.c ft_get_next_line.c ft_atoi.c
SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILE))

INCLUDE_FILE = libft.h
INCLUDE_DIR = include

OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILE))


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@  $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
