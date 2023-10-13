#include "../include/so_long.h"

void	ft_free_map(t_game_instance *game_init)
{
	int i;

	if (game_init->map_init.matrice == NULL)
		return ;
	i = 0;
	while (game_init->map_init.matrice[i])
	{
		free(game_init->map_init.matrice[i]);
		i++;
	}
	free(game_init->map_init.matrice);
	game_init->map_init.matrice == NULL;
	return ;
}