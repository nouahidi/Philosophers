NAME = philo
INC = philo.h
SRC = main_threads.c philo_util.c philo_util2.c philo_util3.c
CC = cc
CFLAGE =  -Wall -Wextra -Werror -g -fsanitize=thread
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGE) -o $@ $^ -g

%.o:%.c $(INC)
	$(CC) $(CFLAGE) -c $<

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : fclean all