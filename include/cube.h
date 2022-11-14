#ifndef CUBE_H
#define CUBE_H

#define SCREEN_WIDTH        640
#define SCREEN_HEIGHT       480

typedef struct s_color
{
	unsigned int	blue:8;
	unsigned int	green:8;
	unsigned int	red:8;
	unsigned int	padd:8;
}	t_color;

typedef struct s_map_info
{
    char    	*path_north_texture;
    char    	*path_south_texture;
    char    	*path_west_texture;
    char    	*path_east_texture;
    t_color 	floor;
    t_color 	 ceil;
	int     	**map;
} t_map_info;

typedef struct s_vector
{
	double	x;
	double	y;
} t_vector;

typedef struct s_map
{
	int	x;
	int	y;
} t_map_pos;

typedef enum e_hit
{
	NO = 0,
	HORIZON,
	VERTICAL
} t_hit;

typedef struct s_bitmap_slice
{
	int	offset_x;
	int	offset_y;
} t_bitmap_slice;

typedef struct s_screen_slice
{	
	int	draw_top;
	int	draw_bottom;
} t_screen_slice;

typedef struct s_draw_info
{
	t_bitmap_slice	bitmap;
	t_screen_slice	screen;
} t_draw_info;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	view;
} t_player;

typedef struct s_game_info
{
	t_map_info	map;
	t_player	player;
} t_game_info;

#endif
