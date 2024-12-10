SRCS	= srcs/main.c srcs/check_map.c srcs/grid_to_lines.c  srcs/place_square.c srcs/ft_split.c srcs/utilities.c
OBJS	= ${SRCS:.c=.o}
INCL	= include
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
NAME	= bsq

.c.o :	
			${CC} -I ${INCL} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@${CC} -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all
	
.PHONY :	all ${NAME} clean fclean re
