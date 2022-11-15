#CC=gcc
CC=cc
#CFLAGS=-Wall -Wextra -Werror -g -I./include -I../minilibx-linux
CFLAGS=-Wall -Wextra -Werror -g -I./include

MANDATORY_DIR=mandatory/
SRCS= main.c find_wall.c fill_wall_slice.c mlx_draw.c correct_wall_distance.c 


BONUS_DIR=bonus/
BONUS_SRCS=

LIB_SRCS=libft/libft.a gnl/libgnl.a

MANDATORY_OBJS=$(addprefix $(MANDATORY_DIR), $(patsubst %.c, %.o, $(SRCS)))
BONUS_OBJS=$(addprefix $(BONUS_DIR), $(patsubst %.c, %.o, $(BONUS_SRCS)))

ifeq ($(BONUS), 1)
	OBJECTS=$(BONUS_OBJS)
else		
	OBJECTS=$(MANDATORY_OBJS)
endif

NAME=cub3D

all:$(NAME)

$(NAME):$(OBJECTS) $(LIB_SRCS)
	$(CC) $(CFLAGS) -v -o $@ $^ -L. -lmlx -framework OpenGL -framework AppKit
#$(CC) $(CFLAGS) -o $@ $^ -L../minilibx-linux -lmlx -lXext -lX11 -lm
# -fsanitize=address 
$(LIB_SRCS) :
	cd libft && make
	cd gnl && make

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

bonus:
	make BONUS=1

clean:
	cd libft && make clean
	cd gnl && make clean
	rm -rf $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean:clean
	cd libft && make fclean
	cd gnl && make fclean
	rm -rf $(NAME)

re:fclean all

.PHONY: clean fclean re bonus
