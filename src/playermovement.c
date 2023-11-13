#include "../include/so_long.h"

static void	player_update_image(char key, t_game_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	if (key == 'w')
		game->player = mlx_xpm_file_to_image
			(game->mlx_ptr, "sprites/xpm/player/back.xpm", \
			&game->img_w, &game->img_h);
	else if (key == 's')
		game->player = mlx_xpm_file_to_image
			(game->mlx_ptr, "sprites/xpm/player/front.xpm", \
			&game->img_w, &game->img_h);
	else if (key == 'd')
		game->player = mlx_xpm_file_to_image
			(game->mlx_ptr, "sprites/xpm/player/right.xpm", \
			&game->img_w, &game->img_h);
	else if (key == 'a')
		game->player = mlx_xpm_file_to_image
			(game->mlx_ptr, "sprites/xpm/player/left.xpm", \
			&game->img_w, &game->img_h);
}

void	player_w(t_game_data *game)
{
	player_update_image('w', game);
	if (game->map[game->player_y][game->player_x] == 'E' && game->n_collect == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		game->map[game->player_y + 1][game->player_x] = '0';
		game->steps++;
		game->endgame = 1;
		ft_draw_map(game);
		print_winner(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y += 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		game->steps++;
		ft_draw_map(game);
	}
}

void	player_s(t_game_data *game)
{
	player_update_image('s', game);
	if (game->map[game->player_y][game->player_x] == 'E' && game->n_collect == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		game->map[game->player_y - 1][game->player_x] = '0';
		game->steps++;
		game->endgame = 1;
		ft_draw_map(game);
		print_winner(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y -= 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		game->steps++;
		ft_draw_map(game);
	}
}

void	player_d(t_game_data *game)
{
	player_update_image('d', game);
	if (game->map[game->player_y][game->player_x] == 'E' && game->n_collect == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		game->map[game->player_y][game->player_x - 1] = '0';
		game->steps++;
		game->endgame = 1;
		ft_draw_map(game);
		print_winner(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x -= 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
		game->steps++;
		ft_draw_map(game);
	}
}

void	player_a(t_game_data *game)
{
	player_update_image('a', game);
	if (game->map[game->player_y][game->player_x] == 'E' && game->n_collect == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		game->map[game->player_y][game->player_x + 1] = '0';
		game->steps++;
		game->endgame = 1;
		ft_draw_map(game);
		print_winner(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x += 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		game->steps++;
		ft_draw_map(game);
	}
}