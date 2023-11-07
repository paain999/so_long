/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:24 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/07 23:01:00 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_and_exit(t_game_data *game)
{
	int i;
	
	i = 0;
	if(game->window)
		mlx_destroy_window(game->mlx_ptr, game->window);
	free(game->mlx_ptr);
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	exit(1);
}

int main(int argc, char **argv)
{
	t_game_data	game;
	t_map_err map_err;
	//int i;
	
	//i = 0;
	map_err = err_list();
	ft_memset(&game, 0, sizeof(t_game_data)); //MALLOC
	game.map = check_params(argc, argv, &game, map_err); //MALLOC
	check_path(&game, &map_err);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		free_and_exit(&game);
	game.window = mlx_new_window(game.mlx_ptr, (SIZE * game.n_col), (SIZE * game.n_row), "SO LONG ADVENTURE TIME!");
	if (!game.window)
		free_and_exit(&game);
	ft_put_graphics(&game);
	/*while (game.map[i])
	{
		ft_putstr_fd(game.map[i++], 1);
		ft_putchar_fd('\n', 1);
	}*/
	mlx_loop(game.mlx_ptr);
	return (0);
}
