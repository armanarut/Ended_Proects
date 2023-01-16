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

LIBFT = 		libft.a
NAME =			libftprintf.a
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
RM =			/bin/rm -f
#OPTION =		-I ft_printf.h
SRCS =			ft_printf.c ft_printf_nbr.c ft_printf_hex.c \
			ft_printf_str.c ft_flags1.c ft_flags2.c
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
			$(MAKE) bonus -C ./libft
			cp libft/${LIBFT} $(NAME)
			ar rcs ${NAME} ${OBJS}
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

run:		all
			${CC} ${CFLAGS} ${NAME} && ./a.out

clean:
			$(MAKE) clean -C ./libft
			${RM} ${OBJS} ${BONUS_OBJS}
			@echo "${YELLOW}Cleaned!$(DEF_COLOR)"

fclean: clean
			$(MAKE) fclean -C ./libft
			${RM} ${NAME} a.out
			@echo "${YELLOW}All cleaned!$(DEF_COLOR)"

re: fclean all

bonus:	$(NAME)

.PHONY:		all clean fclean re bonus run