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

typedef struct s_img
{
	unsigned int	*addr;
	int				bpp;
	int				size_line;
	int				endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}	t_mlx;

typedef struct s_parse_info
{
    char    	*path_north_texture;
    char    	*path_south_texture;
    char    	*path_west_texture;
    char    	*path_east_texture;
	int     	**map;
	t_color 	floor;
    t_color 	 ceil;
}	t_parse_info;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef enum e_hit
{
	NO = 0,
	WALL_HORIZON,
	WALL_VERTICAL
}	t_hit;

typedef struct s_player_info
{
	t_vector	pos;
	t_vector	dir;
	t_vector	view;
}	t_player_info;

typedef struct s_game_info
{
	t_parse_info	parse;
	t_player_info	player;
	t_mlx			mlx;
	t_img			img;
}	t_game_info;

typedef struct s_wall_pos
{
	int	x;
	int	y;
}	t_wall_pos;

typedef struct s_wall_info
{
	double 		corrected_distance;
	t_wall_pos	pos;
	t_hit		hit_side;
}	t_wall_info;

#endif
