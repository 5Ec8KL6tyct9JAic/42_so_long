/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalerio <dvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:27:42 by dvalerio          #+#    #+#             */
/*   Updated: 2023/12/08 15:35:12 by dvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map(t_game_instance *game_init)
{
	int	i;

	if (game_init->map_init.matrice == NULL)
		return ;
	i = 0;
	while (game_init->map_init.matrice[i])
	{
		free(game_init->map_init.matrice[i]);
		i++;
	}
	free(game_init->map_init.matrice);
	game_init->map_init.matrice = NULL;
	return ;
}

void	ft_free_img(t_game_instance *game_init)
{
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_up);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_left);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_right);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_down);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.collectible);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.exit_open);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.exit_close);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.floor);
	game_init->game_objs = (t_game_objs){0};
}
