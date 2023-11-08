#include "../include/so_long.h"

static void	write_move(t_game_data *game)
{
	ft_putstr_fd("Steps Taken: ", 1);
	ft_putnbr_fd(game->steps, 1);
	write(1, "\n", 1);
	ft_putstr_fd("Collectables Remaining: ", 1);
	ft_putnbr_fd(game->n_collect, 1);
	write(1, "\n", 1);
}

static int	right_move(t_game_data *game, int i, int j)
{
	if (game->map[j][i] == 'O')
		show_exit(game, "You Have Won, Congrats!\n");
	if (game->map[j][i] == 'E')
		return (0);
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->player_x = i;
		game->player_y = j;
		game->steps++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->player_x = i;
		game->player_y = j;
		game->n_collect--;
		if (game->n_collect == 0)
		{
			game->map[game->exit_x][game->exit_y] = 'O';
			ft_put_scene(game, game->exit_x, game->exit_y);
		}
		game->steps++;
	}
	return (1);
}

static int	keyboard_w_s(t_game_data *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y;
	if (movement == 13)
	{
		if (game->map[--j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		if (game->map[++j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	return (1);
}

static int	keyboard_a_d(t_game_data *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y;
	if (movement == 0)
	{
		if (game->map[j][--i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 2)
	{
		if (game->map[j][++i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	return (1);
}

int	controls(int keycode, t_game_data *game)
{
	int	works;

	if (keycode == ESC)
		free_and_exit(game);
	if (keycode == W || keycode == UP)
		works = keyboard_w_s(game, keycode);
	if (keycode == S || keycode == DOWN)
		works = keyboard_w_s(game, keycode);
	if (keycode == A || keycode == LEFT)
		works = keyboard_a_d(game, keycode);
	if (keycode == D || keycode == RIGHT)
		works = keyboard_a_d(game, keycode);
	if (works)
	{
		ft_put_graphics(game);
		write_move(game);
	}
	return (1);
}