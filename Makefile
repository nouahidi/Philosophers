NAME = philo
INC = philo.h
SRC = main_threads.c philo_util.c
CC = cc
CFLAGE = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGE) -o $(NAME)

%.o:%.c $(INC)
	$(CC) $(CFLAGE) - c

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : fclean all