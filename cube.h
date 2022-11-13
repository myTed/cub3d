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

typedef struct s_dda
{
    double  	delta_dist_horizon;
    double  	delta_dist_vertical;
    double  	first_dist_horizon;
    double  	first_dist_vertical;
    int			step_horizon;
    int			step_vertical;
	t_hit		hit_side;
    t_map_pos	map_pos;
} t_dda;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	view;
	t_vector	ray;
} t_player;

#endif
