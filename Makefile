CC=cc
#CC=gcc
#CFLAGS=-Wall -Wextra -Werror -g -I./include -I../minilibx-linux -I/usr/include/X11

CFLAGS += -Wall -Wextra -Werror #-O3
CFLAGS += -I ./include
CFLAGS += -I ./libft
CFLAGS += -I ./gnl
CFLAGS += -I ./parse
CFLAGS += -I ./mymlx
CFLAGS += -I ./key
CFLAGS += -I ./raycast

MANDATORY_DIR=mandatory/
SRCS= main.c

PARSE_DIR	=		parse/
PARSE_SRCS	=		parse_main.c \
					parse_identifier_line.c \
					parse_identifier_color.c \
					parse_identifier_utils.c \
					parse_map_size.c \
					parse_map_data.c \
					parse_map_error.c \
					parse_map_error_utils.c \
					parse_utils.c \

MYMLX_DIR	=		mymlx/
MYMLX_SRCS	=		mymlx_init.c \
					mymlx_utils.c

KEY_DIR		=		key/
KEY_SRCS	=		key_init.c\
					key_calculate_pos.c\
					key_move_player.c\
					key_press.c\
					key_update_player.c

RAYCAST_DIR		=	raycast/
RAYCAST_SRCS	=	raycast_main.c \
					correct_wall_distance.c \
					find_wall.c \
					fill_wall_slice.c \
					fill_wall_slice_utils.c \

BONUS_DIR=bonus/

LIB_SRCS=libft/libft.a gnl/libgnl.a

MANDATORY_OBJS	=	$(addprefix $(MANDATORY_DIR), $(SRCS:.c=.o))
MANDATORY_OBJS	+=	$(addprefix $(MANDATORY_DIR)$(PARSE_DIR), $(PARSE_SRCS:.c=.o))
MANDATORY_OBJS	+=	$(addprefix $(MANDATORY_DIR)$(MYMLX_DIR), $(MYMLX_SRCS:.c=.o))
MANDATORY_OBJS	+=	$(addprefix $(MANDATORY_DIR)$(KEY_DIR), $(KEY_SRCS:.c=.o))
MANDATORY_OBJS	+=	$(addprefix $(MANDATORY_DIR)$(RAYCAST_DIR), $(RAYCAST_SRCS:.c=.o))

BONUS_OBJS += $(addprefix $(BONUS_DIR), $(patsubst %.c, %.o, $(addsuffix .c, $(addsuffix _bonus, $(basename $(SRCS))))))
BONUS_OBJS += $(addprefix $(BONUS_DIR)$(PARSE_DIR), $(patsubst %.c, %.o, $(addsuffix .c, $(addsuffix _bonus, $(basename $(PARSE_SRCS))))))
BONUS_OBJS += $(addprefix $(BONUS_DIR)$(MYMLX_DIR), $(patsubst %.c, %.o, $(addsuffix .c, $(addsuffix _bonus, $(basename $(MYMLX_SRCS))))))
BONUS_OBJS += $(addprefix $(BONUS_DIR)$(KEY_DIR), $(patsubst %.c, %.o, $(addsuffix .c, $(addsuffix _bonus, $(basename $(KEY_SRCS))))))
BONUS_OBJS += $(addprefix $(BONUS_DIR)$(RAYCAST_DIR), $(patsubst %.c, %.o, $(addsuffix .c, $(addsuffix _bonus, $(basename $(RAYCAST_SRCS))))))

ifeq ($(BONUS), 1)
	OBJECTS=$(BONUS_OBJS)
else		
	OBJECTS=$(MANDATORY_OBJS)
endif

NAME=cub3D

all:$(NAME)
	
$(NAME): $(OBJECTS) $(LIB_SRCS)
	$(CC) $(CFLAGS) -v -o $@ $^ -lmlx -framework OpenGL -framework AppKit
#	$(CC) $(CFLAGS) -o $@ $^ -L../minilibx-linux -lmlx -lXext -lX11 -lm

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
	rm -rf $(MANDATORY_OBJS) $(BONUS_OBJS)
	rm -rf $(NAME)

re:fclean all

.PHONY: clean fclean re bonus
