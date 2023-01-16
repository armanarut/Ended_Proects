# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 20:20:08 by akazarya          #+#    #+#              #
#    Updated: 2022/04/07 01:15:06 by akazarya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

LIB = 			printf/libftprintf.a
LIB_DIR =		-C ./printf
NAME =			push_swap

CC =			cc
CFLAGS =		-Wall -Wextra -Werror
RM =			/bin/rm -f
#OPTION =		-I ft_printf.h
SRCS =			main.c push_swap.c check_rules.c check_compare.c \
					check_compare_chose.c operations.c utils.c utils2.c
OBJS =			${SRCS:.c=.o}
BONUS_NAME =	checker
BONUS_SRCS =	checker.c operations_bonus.c utils.c utils2.c
BONUS_OBJS =	${BONUS_SRCS:.c=.o}

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

all:		$(NAME)

$(NAME):	${OBJS}
			$(MAKE) bonus ${LIB_DIR}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB}
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

run:		all
			./${NAME}

clean:
			$(MAKE) clean ${LIB_DIR}
			${RM} ${OBJS} ${BONUS_OBJS}
			@echo "${YELLOW}Cleaned!$(DEF_COLOR)"

fclean: clean
			$(MAKE) fclean ${LIB_DIR}
			${RM} ${NAME} $(BONUS_NAME)
			@echo "${YELLOW}All cleaned!$(DEF_COLOR)"

re: fclean all

bonus:	$(BONUS_NAME)
$(BONUS_NAME):	${BONUS_OBJS}
			$(MAKE) bonus ${LIB_DIR}
			${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ${LIB}
			@echo "$(GREEN)$(BONUS_NAME) compiled!$(DEF_COLOR)"

.PHONY:		all clean fclean re bonus run