#include "../include/so_long.h"

int ft_map_extensions(char *map)
{
	char		*extension;
	char		*file_extension;
	static int 	file_count;

	file_count = 0;
	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map)-1] == '/')
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

int get_rows_count(t_game_instance *game_init)
{
	int row_index;
	int row_len;

	row_index = 0;
	while (game_init->map_init.matrice[row_index])
	{
		row_len = ft_strlen(game_init->map_init.matrice[row_index])
				- (game_init->map_init.matrice[row_index]
				[ft_strlen(game_init->map_init.matrice)] - 1 == '\n');
		if (row_len)
	}
}