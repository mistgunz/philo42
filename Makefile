NAME = philo
SRC_DIR = sauce
OBJ_DIR = .objs

SRC =	$(SRC_DIR)/action.c \
		$(SRC_DIR)/errors.c \
		$(SRC_DIR)/forks.c \
		$(SRC_DIR)/philos.c \
		$(SRC_DIR)/thread.c \
		$(SRC_DIR)/time.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/routine.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = gcc
HEAD = -I./include
CFLAGS = -Wall -Werror -Wextra 
LFLAGS = -pthread
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

clean:
		@$(RM) $(OBJ_DIR)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PONY: all clean fclean re
