CC		= cc
FLAGS	= -Wall -Wextra -Werror
NAME	= minitalk.a
SERVER  = server
CLIENT 	= client
LIBC	= ar rc
SRCS	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
RM		= rm -f


all : ${NAME}
${NAME}: ${OBJS}
	${CC} server.c ft_utilty.c -o ${SERVER}
	${CC} client.c ft_utilty.c -o ${CLIENT}
	${LIBC} ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
	${RM} ${SERVER}
	${RM} ${CLIENT}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY:clean fclean re
