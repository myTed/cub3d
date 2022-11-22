CC=cc
#CC=gcc
#CFLAGS=-Wall -Wextra -Werror -g -I./include -I../minilibx-linux -I/usr/include/X11
CFLAGS=-Wall -Wextra -Werror -g -I./include

MANDATORY_DIR=mandatory/
SRCS= main.c free_memory.c keys.c update_player.c \

PARSE_DIR		=	parse/
PARSE_SRCS	=	parse_main.c \
							parse_identifier_line.c \
							parse_identifier_color.c \
							parse_identifier_utils.c \
							parse_map_size.c \
							parse_map_data.c \
							parse_map_error.c \
							parse_map_utils.c \
							parse_map_error_utils.c

MYMLX_DIR		=	mymlx/
MYMLX_SRCS	=	mymlx_init.c \
							mymlx_utils.c

KEY_DIR		=	key/
KEY_SRCS	=	key_init.c

RAYCAST_DIR		=	raycast/
RAYCAST_SRCS	=	raycast_main.c \
								correct_wall_distance.c \
								find_wall.c \
								fill_wall_slice.c \
								fill_wall_slice_utils.c \
								

BONUS_DIR=bonus/
BONUS_SRCS=

LIB_SRCS=libft/libft.a gnl/libgnl.a

MANDATORY_OBJS	=	$(addprefix $(MANDATORY_DIR), $(notdir $(SRCS:.c=.o))) \
									$(addprefix $(MANDATORY_DIR)$(PARSE_DIR), $(notdir $(PARSE_SRCS:.c=.o))) \
									$(addprefix $(MANDATORY_DIR)$(MYMLX_DIR), $(notdir $(MYMLX_SRCS:.c=.o))) \
									$(addprefix $(MANDATORY_DIR)$(KEY_DIR), $(notdir $(KEY_SRCS:.c=.o))) \
									$(addprefix $(MANDATORY_DIR)$(RAYCAST_DIR), $(notdir $(RAYCAST_SRCS:.c=.o)))

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
#	$(CC) $(CFLAGS) -o $@ $^ -L../minilibx-linux -lmlx -lXext -lX11 -lm
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

fclean:
	cd libft && make fclean
	cd gnl && make fclean
	rm -rf $(MANDATORY_OBJS) $(BONSU_OBJS)
	rm -rf $(NAME)

re:fclean all

.PHONY: clean fclean re bonus
