NAME = philo
CC = cc
INCLUDES = -I. -I./allocs -I./utils
CFLAGS = -Wextra -Werror -Wall $(INCLUDES) -g # -fsanitize=address

OBJ_DIR = ../obj
SRC_ALLOCS = allocs/allocs.c allocs/alloc_utils1.c allocs/alloc_utils2.c
SRC_UTILS = utils/utils.c utils/utils_utils1.c utils/utils_utils2.c utils/utils_utils3.c utils/utils_utils4.c
SRC = main.c
SRC += $(SRC_ALLOCS) $(SRC_UTILS)
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re