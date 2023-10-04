#include "../headers//so_long.h"

int main(void)
{
	t_ptr ptr;
	//t_vars vars;

	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 200, 200, "window");
	ptr.mlx = mlx_ptr;
	ptr.win = win_ptr;
	mlx_key_hook(ptr.win, key_check, &ptr);
	mlx_loop(mlx_ptr);
}