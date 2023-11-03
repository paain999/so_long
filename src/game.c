/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:49:06 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/03 12:55:22 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void init(t_map_data map_data, t_game_data game)
{
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return NULL;
	game.window = mlx_new_window(game.mlx_ptr, map_data.n_col * SIZE, map_data.n_row * SIZE, "SO LONG");
	if (!game.window)
	{
		free(game.mlx_ptr);
		return NULL;
	}
}