#ifndef CUB3D_H
# define CUB3D_H

#include "list.h"
#include "get_next_line.h"
#include <stdbool.h>
#define SIDE_SQUARE 64

typedef struct s_map
{
	int		width;
	int		height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	bool	duplicated;
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
void	print_error(char *message);

#endif
