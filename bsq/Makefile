
CC = gcc

CFLAGS = -Wall -Werror -Wextra -I.

NAME = bsq

OBJS = main.o sol.o sol2.o usual_fc.o mapping.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
