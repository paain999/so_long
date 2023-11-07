/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:24 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/07 10:28:34 by dajimene         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_game_data	game;
	t_map_err map_err;
	int i;
	
	i = 0;
	map_err = err_list();
	ft_memset(&game, 0, sizeof(t_game_data)); //MALLOC
	game.map = check_params(argc, argv, &game, map_err); //MALLOC
	check_path(game, map_err);
	//init(game);
	while (game.map[i])
	{
		ft_putstr_fd(game.map[i++], 1);
		ft_putchar_fd('\n', 1);
	}
	free_and_exit(game);
	return (0);
}
