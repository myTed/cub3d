#ifndef CUB3D_H
#define CUB3D_H

#define SCREEN_WIDTH	1000
#define SCREEN_HEIGHT	1000

#define	TEXTURE_MAX		4

#define TRUE 1
#define FALSE 0

#define SUCCESS 0
#define FAIL 1

#include "key.h"

/*
 * UTILS
 */

typedef struct s_img
{
	void			*img_ptr;
	unsigned int	*p_data;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
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
 * STRUCTS
 */

typedef union u_path_info
{
	char *arry[TEXTURE_MAX];
	struct s_texture
	{
		char	*north;/*할당*/
		char	*south;
		char	*west;
		char	*east;
	} texture;
} t_path_info;


typedef struct s_map_info
{
	char	**data;/*할당*/
	int		width;
	int		height;
} t_map_info;

typedef struct s_parse_info
{
	t_path_info	path;
    t_color		floor;
    t_color		ceiling;
	t_map_info	map;
} t_parse_info;

typedef struct s_player_info
{
	t_vector	pos;
	t_vector	dir;
	t_vector	view;
}	t_player_info;

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	screen;
	t_img	north_img;
	t_img	south_img;
	t_img	west_img;
	t_img	east_img;
}	t_mlx_info;

typedef struct s_game_info
{
	t_parse_info		parse;
	t_player_info		player;
	t_mlx_info			mlx;
	t_key_info			key;
}	t_game_info;

#endif
