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
	system("leaks so_long");
}

static void	init_imgs(t_game_data *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/xpm/floor.xpm", &game->img_w, &game->img_h);
	if (!game->floor)
		ft_putstr_fd("Error, Failed to load floor image\n", 2);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/xpm/wall.xpm", &game->img_w, &game->img_h);
	if (!game->wall)
		ft_putstr_fd("Error, Failed to load wall image\n", 2);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/xpm/player/front.xpm", &game->img_w, &game->img_h);
	if (!game->player)
		ft_putstr_fd("Error, Failed to load player image\n", 2);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/xpm/exit-closed.xpm", &game->img_w, &game->img_h);
	if (!game->exit)
		ft_putstr_fd("Error, Failed to load exit image\n", 2);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/xpm/coin-bag.xpm", &game->img_w, &game->img_h);
	if (!game->collectable)
		ft_putstr_fd("Error, Failed to load collectable image\n", 2);
}

void	init(t_game_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		free_and_exit(game, 2);
	game->window = mlx_new_window(game->mlx_ptr, (SIZE * game->n_col + SIZE), (SIZE * game->n_row + SIZE), "SO LONG ADVENTURE TIME!");	
	if (!game->window)
		free_and_exit(game, 2);
	init_imgs(game);
	ft_draw_map(game);
	ft_gamehooks(game);
	mlx_loop(game->mlx_ptr);
}