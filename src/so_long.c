/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:24 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/14 21:22:33 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map_err	err_list(void)
{
	t_map_err	map_err;

	map_err.inv_borders = 0;
	map_err.inv_n_collect = 0;
	map_err.inv_n_exit = 0;
	map_err.inv_rowlen = 0;
	map_err.empty_line = 0;
	map_err.inv_n_player = 0;
	map_err.inv_char = 0;
	map_err.inv_path = 0;
	return(map_err);
}

void	free_and_exit(t_game_data *game, int n_exit)
{
	int i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	mlx_destroy_image(game->mlx_ptr, game->player);
	mlx_destroy_image(game->mlx_ptr, game->wall);
	mlx_destroy_image(game->mlx_ptr, game->collectable);
	mlx_destroy_image(game->mlx_ptr, game->exit);
	mlx_destroy_image(game->mlx_ptr, game->floor);
	if(game->window)
		mlx_destroy_window(game->mlx_ptr, game->window);
	exit(n_exit);
}

int main(int argc, char **argv)
{
	t_game_data	game;
	t_map_err map_err;

	map_err = err_list();
	ft_memset(&game, 0, sizeof(t_game_data));
	check_params(argc, argv, &game, map_err);
	check_path(&game, &map_err);
	init(&game);
	return (0);
}
