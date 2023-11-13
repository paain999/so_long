#include "../include/so_long.h"

static void	ft_game_controls(int keycode, t_game_data *game)
{
	if (keycode == W || keycode == UP)
	{
		game->player_y -= 1;
		player_w(game);
	}
	else if (keycode == S || keycode == DOWN)
	{
		game->player_y += 1;
		player_s(game);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		game->player_x += 1;
		player_d(game);
	}
	else if (keycode == A || keycode == LEFT)
	{
		game->player_x -= 1;
		player_a(game);
	}
}

static int keypressed(int keycode, t_game_data *game)
{
	if (keycode == ESC)
		free_and_exit(game, 0);
	else if (!game->endgame)
		ft_game_controls(keycode, game);
	return (0);
}

void ft_gamehooks(t_game_data *game)
{
	mlx_hook(game->window, 2, 1L << 0, keypressed, game);
	mlx_hook(game->window, 17, 1L << 17, (void *)free_and_exit, game);
	mlx_hook(game->window, 9, 1L << 21, (void *)ft_draw_map, game);
}