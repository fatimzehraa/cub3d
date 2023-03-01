#ifndef CUB3D_H
# define CUB3D_H

#include "list.h"
#include "get_next_line.h"
#include <stdbool.h>
#include <fcntl.h>
#define SIDE_SQUARE 64

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	t_list	*header;
	int		width;
	int		height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	bool	duplicated;
	t_color	floor;
	t_color	ceiling;
	t_list	*lines;
}	t_map;

typedef struct s_ctx
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_ctx;

int	args_err(int argc, char *argv[]);
t_list	*parse(char *filename, t_map *map);
int check_dup(t_map *map);
int map_began(char *content);
void split_map(t_map **map);
int	check_header(t_map **map);
int parse_north(t_map **map, char *texture);
int parse_south(t_map **map, char *texture);
int parse_west(t_map **map, char *texture);
int parse_east(t_map **map, char *texture);
int parse_color(t_map **map, char *color, char *type);
void	print_error(char *message);

#endif
