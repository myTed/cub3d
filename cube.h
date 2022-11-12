#ifndef CUBE_H
#define CUBE_H

#define PATH_MAX            128
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
    char    	path_north_texture[PATH_MAX];
    char    	path_south_texture[PATH_MAX];
    char    	path_west_texture[PATH_MAX];
    char    	path_east_texture[PATH_MAX];
    t_color 	floor;
    t_color 	 ceil;
	int     	**map;
} t_map_info;

typedef struct s_pos
{
	double	x;
	double y;
} t_pos;

typedef struct s_dir
{
	double	x;
	double	y;
} t_dir;

typedef struct s_view
{
	double x;
	double y;
} t_view;

typedef struct s_ray
{
	double x;
	double y;
} t_ray;

typedef struct s_map
{
	int	x;
	int	y;
} t_map;

typedef enum e_hit
{
	NO = 0,
	HORIZON,
	VIRTICAL
} t_hit;

typedef struct s_dda
{
    double  delta_dist_horizon;
    double  delta_dist_vertical;
    double  first_dist_horizon;
    double  first_dist_vertical;
    int     step_horizon;
    int     step_vertical;
	t_hit	hit_side;
    t_map   map_pos;
} t_dda;

typedef struct s_vector
{
    t_pos   pos;
    t_dir   dir;
    t_view  view;
    t_ray   ray;
} t_vector;

#endif
