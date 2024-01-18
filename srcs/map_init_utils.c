/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalerio <dvalerio@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:27:30 by dvalerio          #+#    #+#             */
/*   Updated: 2024/01/18 15:26:08 by dvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to calculate the dimensions of the game map by counting
//		the number of rows, columns and matrice
int	ft_map_dimensions(t_game_instance *game_init)
{
	game_init->map_init.cols_matrice = get_cols_count(&game_init->map_init);
	printf("ROWS INIT MAP MATRICE %d\n", get_rows_count(game_init));
	printf("COLS INIT MAP MATRICE %d\n", get_cols_count(&game_init->map_init));
	if (game_init->map_init.rows_matrice == 0)
		printf("C'est ici c'est cassé\n");
	if (game_init->map_init.cols_matrice == 0)
		return (0);
	printf("\n");
	return (get_rows_count(game_init));
}

int	get_cols_count(t_map_data *map_init)
{
	char	*row;
	int		cols_count;

	row = map_init->matrice[0];
	cols_count = 0;
	while (*row && *row != '\n')
	{
		cols_count++;
		row++;
	}
	printf("Number of cols %d\n", cols_count);
	return (cols_count);
}

int	get_rows_count(t_game_instance *game_init)
{
	int	row_index;
	int	row_len;

	row_index = 0;
	while (game_init->map_init.matrice[row_index])
	{
		row_len = ft_strlen(game_init->map_init.matrice[row_index])
				- (game_init->map_init.matrice[row_index]
					[ft_strlen(game_init->map_init.matrice[row_index]) - 1] == "\n");
			printf("row index avant condition if : %d\n", row_index);
		if (row_len != game_init->map_init.cols_matrice)
		{
			game_init->map_init.rows_matrice = 0;
			return (0);
			printf("row index avant IT : %d", row_index);
		}
		game_init->map_init.rows_matrice++;
		row_index++;
		printf("row index apres IT : %d", row_index);
	}
	game_init->map_init.size_matrice = game_init->map_init.rows_matrice
		* game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_width
		= game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_height
		= game_init->map_init.rows_matrice;
	return (1);
}

// Function to checks if the map has a valid .ber extension and path/
int	ft_map_extension(char *map)
{
	char		*extension;
	char		*file_extension;
	static int	file_count;

	file_count = 0;
	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
	{
		ft_error_map(21);
		return (0);
	}
	else if (!file_extension || !ft_strcmp(file_extension, ""))
		return (0);
	else if (file_extension && !ft_strcmp(file_extension, extension))
	{
		if (file_count >= MAX_FILES)
			return (0);
		file_count++;
	}
	else
		return (0);
	return (1);
}
