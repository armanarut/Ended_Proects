# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 20:20:08 by akazarya          #+#    #+#              #
#    Updated: 2022/05/25 21:41:22 by akazarya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

LIB_DIR			= #libs/printf/
LIB				= $(LIB_DIR)libftprintf.a

NAME			= pipex
SRCS			= main.c pipex.c utils1.c utils2.c ft_split.c
OBJS			= $(SRCS:.c=.o)

CC				= cc
CFLAGS			= -g -Wall -Wextra -Werror
RM				= rm -rf

# Colors

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

all:		$(NAME)

$(NAME):	$(OBJS)
# @cd $(LIB_DIR) && $(MAKE) bonus
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

clean:
# @cd $(LIB_DIR) && $(MAKE) clean
			$(RM) $(OBJS)
			@echo "$(YELLOW)Cleaned!$(DEF_COLOR)"

fclean: clean
# @cd $(LIB_DIR) && $(MAKE) fclean
			$(RM) $(NAME)
			@echo "$(YELLOW)All cleaned!$(DEF_COLOR)"

re: fclean all

bonus: all

.PHONY:		all clean fclean re bonus
