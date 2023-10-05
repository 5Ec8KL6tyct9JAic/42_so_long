#include "../headers/so_long.h"

int my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}

int key_check(int key, t_vars *vars)
{
	if (key == ESC)
		my_close(vars);
	else
		ft_printf("you pressed: %d %n", key);
	return (0);
}
