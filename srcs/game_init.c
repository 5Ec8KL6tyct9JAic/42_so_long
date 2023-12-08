/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalerio <dvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:27:35 by dvalerio          #+#    #+#             */
/*   Updated: 2023/12/08 15:38:12 by dvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_img(t_game_instance *game_init, void **image, char *path)
{
	int	width;
	int	height;

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
		"rscs/textures/Player/Chat_haut.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_down,
		"rscs/textures/Player/Chat_bas.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_right,
		"rscs/textures/Player/Chat_droite.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_left,
		"rscs/textures/Player/Chat_gauche.xpm");
	ft_check_img(game_init, &game_init->game_objs.collectible,
		"rscs/textures/Collectibles/collectible.xpm");
	ft_check_img(game_init, &game_init->game_objs.floor,
		"rscs/textures/Tiles/Grass.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_open,
		"rscs/textures/Exit/chest_open.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_close,
		"rscs/textures/Exit/chest_close.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall,
		"rscs/textures/Tiles/golden_pyramid.xpm");
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
			game_init->map_init.resolutions.settings_map_width
			* CELL_SIZE, game_init->map_init.resolutions.settings_map_height
			* CELL_SIZE, "Meowlicious");
	if (game_init->win_ptr == NULL)
		ft_error_init(38);
}
