#include <unistd.h>
#include <mlx.h>
#include <get_next_line.h>
#include "cub3D.h"

void init_ctx(t_ctx *ctx)
{
	ctx->mlx = NULL;
	ctx->win = NULL;
	ctx->map = NULL;
	ctx->map->lines = NULL;
	ctx->map->east = NULL;
	ctx->map->west = NULL;
	ctx->map->north = NULL;
	ctx->map->south = NULL;
}

int main()
{
	t_ctx ctx;
/*	char map[] = {'1','1','1','1','1','1',
				'1','0','0','1','0','1',
				'1','0','1','0','0','1',
				'1','1','0','0','N','1',
				'1','1','1','1','1','1'};
*/
	//check arguments
	init_ctx(&ctx);
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 600, 600, "mlx 42");
	mlx_loop(mlx);
	(void)win;
	return 0;
}
