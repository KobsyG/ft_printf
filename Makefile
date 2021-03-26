SRCS	= ft_printf.c ft_prec.c ft_form.c ft_print_char.c ft_print_int.c ft_print_maj_uhexa.c\
		  ft_print_ptr.c ft_print_uhexa.c ft_print_uint.c ft_printf_utils.c ft_print_str.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

%.o:		%.c ft_printf.h
			${CC} ${CFLAGS} -o $@ -c $< -I.

all:		${NAME}

${NAME}:	${OBJS}
			make -C ./libft
			cp ./libft/libft.a libftprintf.a
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			make -C ./libft clean

fclean:		clean
			${RM} ${NAME}
			make -C ./libft fclean 

re:			fclean all

bonus:		${NAME}
