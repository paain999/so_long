/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:24 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/10 00:30:40 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_and_exit(t_game_data *game)
{
	int i;
	
	i = 0;
	if(game->window)
		mlx_destroy_window(game->mlx_ptr, game->window);
	if(game->mlx_ptr)
		free(game->mlx_ptr);
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	exit(0);
}

void show_exit(t_game_data *game, char *str)
{
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	free_and_exit(game);
}

int main(int argc, char **argv)
{
	t_game_data	game;
	t_map_err map_err;

	map_err = err_list();
	ft_memset(&game, 0, sizeof(t_game_data));
	game.map = check_params(argc, argv, &game, map_err);
	check_path(&game, &map_err);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		free_and_exit(&game);
	game.window = mlx_new_window(game.mlx_ptr, (SIZE * game.n_col), (SIZE * game.n_row), "SO LONG ADVENTURE TIME!");
	if (!game.window)
		free_and_exit(&game);
	ft_put_images(&game);
	ft_put_graphics(&game);
	mlx_key_hook(game.window, controls, &game);
	mlx_hook(game.window, 17, 0, (void *)free_and_exit, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
