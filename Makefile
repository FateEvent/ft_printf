SRCS	= ft_printf.c basic_ft.c utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs $@ $^

all:		${NAME}

bonus:		${NAME}
			ar -rcs ${NAME}

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re