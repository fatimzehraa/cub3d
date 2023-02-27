#include <unistd.h>
#include <mlx.h>
#include <get_next_line.h>
#include "cub3D.h"

void init_ctx(t_ctx *ctx)
{
	ctx->mlx = NULL;
	ctx->win = NULL;
	//ctx->map = NULL;
	ctx->map.lines = NULL;
	ctx->map.east = NULL;
	ctx->map.west = NULL;
	ctx->map.north = NULL;
	ctx->map.south = NULL;
}
/*
int	set_win(t_ctx *ctx, t_list *lines)
{
	t_list	*cur;
	t_map	*map;
	int		side;

	map = ctx->map;
	map->height = 0;
	cur = lines;
	while (cur)
	{
		(map->height)++;
		cur = cur->next;
	}
	map->height *= SIDE_SQUARE;
	map->width = ft_strlen(lines->content) * SIDE_SQUARE;
	map->character = mlx_xpm_file_to_image
		(ctx->mlx, "images/P.xpm", &side, &side);
	map->way = mlx_xpm_file_to_image(ctx->mlx, "images/0.xpm", &side, &side);
	map->wall = mlx_xpm_file_to_image(ctx->mlx, "images/1.xpm", &side, &side);
	map->coin = mlx_xpm_file_to_image(ctx->mlx, "images/C.xpm", &side, &side);
	map->exit = mlx_xpm_file_to_image(ctx->mlx, "images/E.xpm", &side, &side);
	return (map->character && map->wall && map->coin && map->exit && map->way);
}*/

//int	close_game(void *param)
//{
//	free_ctx((t_ctx *)param);
//	exit(0);
//}



int	main(int argc, char *argv[])
{
	t_ctx	ctx;
	t_list		*lines;

	if (args_err(argc, argv))
		return (1);
	init_ctx(&ctx);
	lines = parse(argv[1], &ctx.map);
	if (lines == NULL)
		return (1);
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 600, 600, "mlx 42");
	mlx_loop(mlx);
	(void)win;
	/*ctx.map.lines = lines;
	if (!set_win(&ctx, lines))
		return (free_ctx(&ctx), 1);
	ctx.win = mlx_new_window(ctx.mlx, ctx.map.width, ctx.map.height, "so_long");
	mlx_key_hook(ctx.win, key_event, &ctx);
	mlx_hook(ctx.win, 17, 0, close_game, &ctx);
	draw(&ctx);
	mlx_loop(ctx.mlx);
	free_ctx(&ctx);*/
	return (0);
}

/*
int main()
{
	t_ctx ctx;
	//check arguments
	init_ctx(&ctx);
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 600, 600, "mlx 42");
	mlx_loop(mlx);
	(void)win;
	return 0;
}*/
