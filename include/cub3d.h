#ifndef CUB3D_H
#define CUB3D_H

#define SCREEN_WIDTH        2000
#define SCREEN_HEIGHT       2000
//#define TEXTURE_WIDTH        128
//#define TEXTURE_HEIGHT       128


#define PLAYER_DIR_X 0
#define PLAYER_DIR_Y -1
#define PLAYER_POS_X 14.5
#define PLAYER_POS_Y 7
#define MAP_SIZE_Y 30
#define MAP_SIZE_X 30


/*
 * UTILS of s_game_info 
 */

typedef struct s_img
{
	void					*img_ptr;
	unsigned int	*addr;
	int						width;
	int						height;
	int						bpp;
	int						size_line;
	int						endian;
}	t_img;

typedef struct s_color
{
	unsigned int	blue:8;
	unsigned int	green:8;
	unsigned int	red:8;
	unsigned int	padd:8;
}	t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

/*
 * KEY STUCTS of s_game_info
 */

typedef struct s_parse_info
{
    t_img			north_img;
    t_img			south_img;
    t_img			west_img;
    t_img			east_img;
    t_color 	floor;
    t_color 	ceiling;
		int  		  **map;
} t_parse_info;

typedef struct s_player_info
{
	t_vector	pos;
	t_vector	dir;
	t_vector	view;
}	t_player_info;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img		screen;
}	t_mlx;

typedef struct s_game_info
{
	t_parse_info		parse;
	t_player_info		player;
	t_mlx						mlx;
}	t_game_info;

/*
 * UTILS
 * of s_wall_dist_info, s_wall_info, s_slice_info
 */

//typedef enum e_texture_kind
//{
//	NORTH,
//	SOUTH,
//	WEST,
//	EAST
//} t_texture_kind;

typedef enum e_hit
{
	NO = 0,
	HORIZON,
	VERTICAL
}	t_hit;

typedef struct s_wall_pos
{
	int	x;
	int	y;
}	t_wall_pos;

/*
 * KEY STRUCTS 
 * of s_wall_dist_info, s_wall_info, s_slice_info
 */

typedef struct s_wall_dist_info
{
	double	vertical;
	double	horizon;
	double	delta_vertical;
	double	delta_horizon;
	int			step_vertical;
	int			step_horizon;
} t_wall_dist_info;

typedef struct s_wall_info
{
	double 			corrected_distance;
	t_wall_pos	pos;
	t_hit				hit_side;
}	t_wall_info;

typedef struct s_slice_info//single slice to work at
{
	t_img			*p_texture_img;
	int				draw_top;//start-pixel in screen
	int				draw_bottom;
	double		texture_offset_x;
	double		texture_offset_y;//usually 0
	double		texture_step_y;//movement per screen pixel y (bigger step -> smaller at screen)
} t_slice_info;

#endif
