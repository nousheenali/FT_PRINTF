# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nali <nali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 11:57:13 by nali              #+#    #+#              #
#    Updated: 2021/11/18 12:14:32 by nali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT	= libft

SRCS	= ft_printf.c ft_putnbr_unsigned.c ft_convert_to_hex.c \
		ft_format_check.c ft_print_functions.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

all:	${NAME}

.c.o:	${CC} ${CFLAGS} -I -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${LIBFT}
			cp libft/libft.a ./${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:		
			${RM} ${OBJS}
			make clean -C ${LIBFT}

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}/libft.a

re:			fclean all

.PHONY:		all clean fclean re .c.o


