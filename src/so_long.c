/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:24 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/15 00:39:47 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_and_exit(t_game_data *game, int n_exit)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->collectable)
		mlx_destroy_image(game->mlx_ptr, game->collectable);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->window)
		mlx_destroy_window(game->mlx_ptr, game->window);
	exit(n_exit);
}

int	main(int argc, char **argv)
{
	t_game_data	game;

	ft_memset(&game, 0, sizeof(t_game_data));
	check_params(argc, argv, &game);
	check_path(&game);
	init(&game);
	return (0);
}