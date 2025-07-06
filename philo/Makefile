# _*_ MakeFile _*_

NAME		= philo
SRC = main.c parsing.c philosopher.c std_utils.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -pthread

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run