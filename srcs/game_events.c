#include "../include/so_long.h"

void	ft_check_img(t_game_instance *game_init, void **image, char *path)
{
	int width;
	int height;

	*image = mlx_xpm_file_to_image(game_init->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		ft_error_init(1);
		ft_exit_program(game_init);
	}
}

void	ft_img_init(t_game_instance *game_init)
{
	ft_check_img(game_init, &game_init->game_objs.player_up,
				 "")
}