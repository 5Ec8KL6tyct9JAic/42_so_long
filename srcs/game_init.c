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

void	ft_initialize_game(t_game_instance *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (game_init->mlx_ptr == NULL)
		ft_error_init(38);
	game_init->game_data.count_movements = 0;
	ft_img_init(game_init);
	game_init->game_objs.player = game_init->game_objs.player_down;
	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr,
										game_init->map_init.resolutions.settigs_map_width
										* CELL_SIZE, game_init->map_init.resolutions.settings_map_height
										* CELL_SIZE, "Meowlicious");
	if (game_init->win_ptr == NULL)
		ft_error_init(38);
}