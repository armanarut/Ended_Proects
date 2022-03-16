# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akazarya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 20:20:08 by akazarya          #+#    #+#              #
#    Updated: 2022/02/24 21:13:10 by akazarya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a
GCC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		/bin/rm -f
HEADER =	./includes/
OPTION =	-c -I ${HEADER}
SRCS_DIR =	./srcs/
SRCS =		${SRCS_DIR}ft_putchar.c ${SRCS_DIR}ft_putstr.c ${SRCS_DIR}ft_strcmp.c \
				${SRCS_DIR}ft_strlen.c ${SRCS_DIR}ft_swap.c
OBJS =		${SRCS:.c=.o}
OBJSD =		ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: 		${NAME}

$(NAME):
			${GCC} ${CFLAGS} ${OPTION} ${SRCS}
			mv ${OBJSD} ${SRCS_DIR}
			ar rc $(NAME) ${OBJS}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} $(NAME)

re: fclean all
