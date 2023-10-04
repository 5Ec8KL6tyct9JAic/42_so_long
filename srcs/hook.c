#include "../headers/so_long.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}
