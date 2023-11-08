/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:49:06 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/08 21:52:23 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_put_images(t_game_data *game)
{
	int i;
	int j;

	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/player.xpm", &i, &j);
	game->exit_open = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/open-exit.xpm", &i, &j);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/exit-closed.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr, "../sprites/xpm/coin-bag.xpm", &i, &j);
}

void ft_put_scene(t_game_data *game, int y, int x)
{
	if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->exit_closed, x * SIZE, y * SIZE);
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (game->map[y][x] == 'O')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->exit_open, x * SIZE, y * SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->floor, x * SIZE, y * SIZE);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->wall, x * SIZE, y * SIZE);
}

static void put_player(t_game_data *game, int y, int x)
{
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->player, x * SIZE, y * SIZE);
}

static void  put_collectable(t_game_data *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->collectable, x * SIZE, y * SIZE);
}



void	ft_put_graphics(t_game_data *game)
{
	int y;
	int x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[x])
		{
			put_player(game, y, x);
			put_collectable(game, y, x);
			ft_put_scene(game, y, x);
		}
		y++;
	}	
}