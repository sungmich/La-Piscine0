# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 18:33:15 by sungmich          #+#    #+#              #
#    Updated: 2022/09/10 11:42:40 by sungmich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
WFLAGS = -Wall -Werror -Wextra
TARGET = do-op
NAME = libft.a
SRCSDIR = srcs
INCLUDE = includes
FILE = ft_atoi.c ft_putnbr.c op.c main.c
SRC = $(addprefix $(SRCSDIR)/, $(FILE))

OBJS = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(NAME)
	$(CC) $(WFALGS) -o $@ $^

$(NAME) : $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -I $(INCLUDE) $^

clean :
	rm -rf $(OBJS) $(NAME)
fclean : clean
	rm -rf $(TARGET)
re : fclean all
