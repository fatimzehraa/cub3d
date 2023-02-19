#include <unistd.h>
#include <mlx.h>
#include <get_next_line.h>

int main()
{
/*	char map[] = {'1','1','1','1','1','1',
				'1','0','0','1','0','1',
				'1','0','1','0','0','1',
				'1','1','0','0','N','1',
				'1','1','1','1','1','1'};
*/
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 600, 600, "mlx 42");
	mlx_loop(mlx);
	win = NULL;
	return 0;
}
