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

LIB_DIR			= libs/printf/
LIB				= $(LIB_DIR)libftprintf.a
LIBMLX_DIR		= libs/minilibx_mms/
LIBMLX			= $(LIBMLX_DIR)libmlx.dylib

NAME			= so_long
SRCS			= so_long.c map_make.c keys.c img_make.c utils1.c utils2.c
OBJS			= $(SRCS:.c=.o)

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
#OPTION			= -I ft_printf.h
MLXFLAGS		= -I $(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit

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
			@cd $(LIB_DIR) && $(MAKE) bonus
			@cd $(LIBMLX_DIR) && $(MAKE)
			$(CC) $(CFLAGS) $(OBJS) -L $(LIB_DIR) -lftprintf $(MLXFLAGS) -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

run:		all
			./$(NAME)

clean:
			@cd $(LIB_DIR) && $(MAKE) clean
			@cd $(LIBMLX_DIR) && $(MAKE) clean
			$(RM) $(OBJS)
			@echo "$(YELLOW)Cleaned!$(DEF_COLOR)"

fclean: clean
			@cd $(LIB_DIR) && $(MAKE) fclean
			$(RM) $(NAME)
			@echo "$(YELLOW)All cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY:		all clean fclean re bonus run