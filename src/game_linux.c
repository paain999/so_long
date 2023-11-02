#include "../include/so_long.h"

void init(char **map, t_map_data map_data)
{
	t_game_data game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return NULL;
	game.window = mlx_new_window(game.mlx_ptr, map_data.n_col * SIZE, map_data.n_row * SIZE, "SO_LONG");
	if (!game.window)
	{
		free(game.mlx_ptr);
		return NULL;
	}
}