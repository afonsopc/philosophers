NAME = philo
CC = cc
INCLUDES = -I./philo
CFLAGS = -Wextra -Werror -Wall $(INCLUDES)

SRC_DIR = philo
OBJ_DIR = obj
BIN_DIR = bin
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
BINARY = $(addprefix $(BIN_DIR)/, $(NAME))

all: $(NAME)

$(NAME): $(BINARY)

$(BINARY): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re