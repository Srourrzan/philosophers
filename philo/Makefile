# _*_ MakeFile _*_

NAME		= philo
SRCS = main.c 			\
		parsing.c 		\
		philosopher.c 	\
		std_utils.c 	\
		simulation.c 	\
		table.c 		\
		monitor.c 		\

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=thread
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -pthread
			
$(OBJ_DIR)/%.o: %.c
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run