#ifndef CUB3D_H
# define CUB3D_H

#include "list.h"
#include "get_next_line.h"
#include <stdbool.h>
#define SQUARE_SIZE 64

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
	t_map	*map;
}	t_ctx;

#endif
