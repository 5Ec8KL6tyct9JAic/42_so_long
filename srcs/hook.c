#include "../headers/so_long.h"
/*
int my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}
*/
int key_check(int key, t_ptr *ptr)
{
	if(key == ESC)
	{
		ft_printf("Fermeture de la fenetre\n");
		mlx_destroy_window(ptr->mlx, ptr->win);
		free(ptr->mlx);
		exit(0);
	}
	else
		ft_printf("t'as appuye sur %c\n", key);
	return(0);
}
