#include "../include/so_long.h"

void	print_winner(t_game_data *game)
{
	int	w;

	w = game->n_col / 2;
	mlx_string_put(game->mlx_ptr, game->window, w, 20, 0xFFFFFF, "WINNER");
	mlx_string_put(game->mlx_ptr, game->window,
		w - 10, 40, 0xFFFFFF, "PRESS ESC");
}

void	display_moves(t_game_data *game)
{
	char	*str;
	char	*n_coins;

	str = ft_itoa(game->steps);
	n_coins = ft_itoa(game->n_collect);
	mlx_string_put(game->mlx_ptr, game->window, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlx_ptr, game->window, 90, 20, 0xFFFFFF, str);
	mlx_string_put(game->mlx_ptr, game->window, 25, 50, 0xFFFFFF, "COINS: ");
	mlx_string_put(game->mlx_ptr, game->window, 90, 50, 0xFFFFFF, n_coins);
	free(str);
	free(n_coins);
}

void	init_imgs(t_game_data *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/floor.xpm", &game->img_w, &game->img_h);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/wall.xpm", &game->img_w, &game->img_h);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/player/front.xpm", &game->img_w, &game->img_h);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/exit_closed.xpm", &game->img_w, &game->img_h);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/coin-bag.xpm", &game->img_w, &game->img_h);
}

void	init(t_game_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		free_and_exit(game);
	game->window = mlx_new_window(game->mlx_ptr, (SIZE * game->n_col), (SIZE * game->n_row), "SO LONG ADVENTURE TIME!");	
	if (!game->window)
		free_and_exit(game);
	init_imgs(game);
	ft_draw_map(game);
	ft_gamehooks(game);
	mlx_loop(game->mlx_ptr);
}