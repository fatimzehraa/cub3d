#ifndef CUB3D_H
# define CUB3D_H

#include "list.h"

#define SQUARE_SIZE 64

typedef struct s_map
{
	int		width;
	int		height;
	t_list	*map;
}	t_map;

typedef struct s_context
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_context;

#endif
