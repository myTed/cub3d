#ifndef PARSE_H
#define PARSE_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 0
#define FAIL 1

#define VIEW_X 0.66
#define VIEW_Y 0

#define	TYPE_MAX		6

#define	COLOR_NUM_MAX	3
#define	COLOR_VALUE_MAX	255
#define	COLOR_VALUE_MIN 0

typedef enum e_type_idx
{
	NORTH_IDX = 0,
	SOUTH_IDX,
	WEST_IDX,
	EAST_IDX,
	FLOOR_IDX,
	CEILING_IDX
} t_type_idx;

typedef enum e_charset
{
	WALL = '1',
	GROUND = '0',
	PLAYER_NORTH = 'N',
	PLAYER_SOUTH = 'S',
	PLAYER_WEST = 'W',
	PLAYER_EAST = 'E',
	OUTSIDE1 = ' ',
	OUTSIDE2 = '\0'
} t_charset;

typedef struct s_type
{
	char 		*str[TYPE_MAX];
	int			found[TYPE_MAX];
} t_type_ident;

#endif
