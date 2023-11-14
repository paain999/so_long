/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:49:06 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/14 10:25:03 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_img(t_game_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window, img, x * SIZE, y * SIZE);
}

static void	player_draw(t_game_data *game, void *image, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	ft_draw_img(game, image, x, y);
}

static void	ft_draw_exit(t_game_data *game, int x, int y)
{
	if (game->n_collect == 0)
	{
		mlx_destroy_image(game->mlx_ptr, game->exit);
		game->exit = mlx_xpm_file_to_image
			(game->mlx_ptr, "./sprites/xpm/open-exit.xpm", &game->img_w, &game->img_h);
	}
	ft_draw_img(game, game->exit, x, y);
}

int	ft_draw_map(t_game_data *game)
{
	int y;
	int x;

	y = -1;
	while (game->map[++y] != (void *)0)
	{
		x = -1;
		while (game->map[++x] != (void *)0)
		{
			if(game->map[y][x] == '1')
				ft_draw_img(game, game->wall, x, y);
			else if(game->map[y][x] == '0')
				ft_draw_img(game, game->floor, x, y);
			else if(game->map[y][x] == 'P')
				player_draw(game, game->player, x, y);
			else if(game->map[y][x] == 'C')
				ft_draw_img(game, game->collectable, x, y);
			else if(game->map[y][x] == 'E')
				ft_draw_exit(game, x, y);
		}
	}
	display_moves(game);
	return 0;
}