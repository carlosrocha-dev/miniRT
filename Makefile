NAME=		miniRT
CC=			gcc
FLAGS=	-Wall -Werror -Wextra -g3
SRCS=		\
				src/main.c


all:
	$(CC) $(SRCS) $(FLAGS) -o $(NAME)


clean:
	rm -f *.o
	rm $(NAME)
