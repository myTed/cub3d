# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 14:38:14 by kyolee            #+#    #+#              #
#    Updated: 2022/06/15 15:23:26 by kyolee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

SRCS=ft_gnl.c ft_gnl_utils.c

OBJS=$(patsubst %.c, %.o, $(SRCS))

NAME=libgnl.a

all:$(NAME)

$(NAME):$(OBJS)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: clean fclean all re bonus

