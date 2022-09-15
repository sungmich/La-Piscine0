# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 18:33:15 by sungmich          #+#    #+#              #
#    Updated: 2022/09/15 05:40:50 by sungmich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = bsq
TXT = stdin.txt
SRCSDIR = srcs
INCLUDE = includes
FILE = main.c check.c map.c map2.c var.c free.c
SRCS = $(addprefix $(SRCSDIR)/, $(FILE))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ -I $(INCLUDE) $^
$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $@ $^
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME) $(TXT)
re : fclean all
