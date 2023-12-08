/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalerio <dvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:27:45 by dvalerio          #+#    #+#             */
/*   Updated: 2023/12/08 15:35:00 by dvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to free() and quit the program
int	ft_exit_program(t_game_instance *game_init)
{
	ft_printf("Good bye little cat\n");
	ft_free_img(game_init);
	ft_free_map(game_init);
	ft_cleanup(game_init);
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	free(game_init->mlx_ptr);
	exit(0);
}

// Function to free() and reset the game (start in the same point)
void	ft_reset_game(t_game_instance *game_init)
{
	ft_printf("\n Yes little cat, we're restarting the game...\n");
	ft_free_img(game_init);
	ft_free_map(game_init);
	free(game_init->resolutions_init.settings_name_window);
	free(game_init->resolutions_init.settings_name_map);
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	free(game_init->mlx_ptr);
	main(game_init->argc_tmp, game_init->argv_tmp);
}

// Function to free the name in window
void	ft_cleanup(t_game_instance *game_init)
{
	if (game_init->resolutions_init.settings_name_window != NULL)
	{
		free(game_init->resolutions_init.settings_name_window);
		game_init->resolutions_init.settings_name_window = NULL;
	}
	if (game_init->resolutions_init.settings_name_map != NULL)
	{
		free(game_init->resolutions_init.settings_name_map);
		game_init->resolutions_init.settings_name_map = NULL;
	}
}
