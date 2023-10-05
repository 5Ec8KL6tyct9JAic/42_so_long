#include "../headers//so_long.h"


int main(void)
{
	t_vars vars;
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 300, "window");
	vars.mlx = mlx_ptr;
	vars.win = win_ptr;

	mlx_key_hook(vars.win, key_check, &vars);

	mlx_loop(mlx_ptr);
	return (0);
}