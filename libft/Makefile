# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 20:15:15 by kyolee            #+#    #+#              #
#    Updated: 2022/06/15 15:23:44 by kyolee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

SRCS=ft_atoi.c     ft_isascii.c  ft_memcpy.c   ft_strdup.c   ft_strncmp.c  ft_tolower.c\
	 ft_bzero.c    ft_isdigit.c  ft_memmove.c  ft_strjoin.c  ft_strnstr.c  ft_toupper.c\
	 ft_calloc.c   ft_isprint.c  ft_memset.c   ft_strlcat.c  ft_strrchr.c\
	 ft_isalnum.c  ft_memchr.c   ft_strcat.c   ft_strlcpy.c  ft_strtrim.c\
	 ft_isalpha.c  ft_memcmp.c   ft_strchr.c   ft_strlen.c   ft_substr.c\
	 ft_split.c    ft_itoa.c     ft_strmapi.c  ft_striteri.c ft_putchar_fd.c\
	 ft_putstr_fd.c\
	 ft_putendl_fd.c\
	 ft_putnbr_fd.c

BONUS_SRCS=ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c\
		   ft_lstadd_back.c	ft_lstdelone.c		ft_lstclear.c	ft_lstiter.c\
		   ft_lstmap.c

BONUS_OBJS=$(patsubst %.c, %.o, $(SRCS) $(BONUS_SRCS))
MANDATORY_OBJS=$(patsubst %.c, %.o, $(SRCS))

ifeq ($(BONUS), 1)
	OBJECTS=$(BONUS_OBJS)
else
	OBJECTS=$(MANDATORY_OBJS)
endif

NAME=libft.a

all:$(NAME)

$(NAME):$(OBJECTS)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

bonus:
	make BONUS=1

clean:
	rm -rf $(BONUS_OBJS) $(MANDATORY_OBJS)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: clean fclean all re bonus
