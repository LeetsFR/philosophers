NAME = philo
CC =  cc -Wall -Wextra -Werror -g3

SRC_FILE = philo.c routine.c utils.c init_data.c init_philo.c init_mutex.c init_mutex_utils.c launch_thread.c
SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILE))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_FILE:.c=.o))

LIBFT_DIR = libft
LIBFT = libft.a

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(OBJ)
	$(CC) -L $(LIBFT_DIR) $(OBJ) -l ft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -I include -I libft/include -c $< -o $@

$(LIBFT_DIR)/$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

