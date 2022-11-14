#ifndef CUBE_H
#define CUBE_H

#define SCREEN_WIDTH        640
#define SCREEN_HEIGHT       480
#define TEXTURE_WIDTH        64
#define TEXTURE_HEIGHT       64

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

typedef struct s_wall_pos
{
	int	x;
	int	y;
} t_wall_pos;

typedef enum e_hit
{
	NO = 0,
	WALL_HORIZON,
	WALL_VERTICAL
} t_hit;

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

typedef struct s_distance
{
	t_vector	ray;
	t_wall_pos	wall_pos;
	double corrected_distance;
	t_hit hit_side;
} t_distance;

#endif
