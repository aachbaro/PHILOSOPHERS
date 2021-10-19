NAME = philo
SRC = SRCS/main.c \
      SRCS/utils.c \

LIBFT = -L./LIBFT -lft
PTHREAD = -pthread
CC = gcc #clang
INC = -I./thread.h
CFLAGS = #-Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -rf
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	@$(MAKE) -C ./LIBFT
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(LIBFT) $(PTHREAD)
	@${RM} ${OBJ}
all: $(NAME)
clean:
	@${RM} ${OBJ}
fclean: clean
	@$(MAKE) fclean -C ./LIBFT
	@${RM} ${SAVE}
	@${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
