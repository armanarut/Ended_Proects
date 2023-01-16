# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akazarya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 20:20:08 by akazarya          #+#    #+#              #
#    Updated: 2022/03/14 22:53:10 by akazarya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME =			libftprintf.a
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
RM =			/bin/rm -f
OPTION =		-c -I ft_printf.h
SRCS =			ft_printf.c ft_printf_nbr.c ft_printf_str.c
OBJS =			${SRCS:.c=.o}
BONUS_OBJS =	${BONUS:.c=.o}

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: 		${NAME}

$(NAME):	${OBJS}

			ar rcs ${NAME} ${OBJS}
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"
clean:
			${RM} ${OBJS} $(BONUS_OBJS)
			@echo "${YELLOW}Cleaned!$(DEF_COLOR)"

fclean: clean
			${RM} ${NAME}
			@echo "${YELLOW}All cleaned!$(DEF_COLOR)"

re: fclean all

bonus:	$(NAME)

.PHONY:		all clean fclean re bonus