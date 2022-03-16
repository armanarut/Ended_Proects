# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akazarya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 20:59:07 by akazarya          #+#    #+#              #
#    Updated: 2022/02/19 21:25:19 by akazarya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAME = rush-02
G = gcc
W = -Wall -Wextra -Werror
FUNCTION = main.c ft_num.c ft_put.c

all: $(FILENAME)

%.o: %.c
	$(G) $(W) -c -o $@ $^

$(FILENAME): $(FUNCTION:.c=.o)
	$(G) $(W) -o $@ $^

clean:
	rm -f $(FUNCTION:.c=.o)

fclean: clean
	rm -f $(FILENAME)

re: fclean $(FILENAME)
