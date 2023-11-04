/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:49:06 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/04 21:17:36 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void init(t_game_data game)
{
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return NULL;
	game.window = mlx_new_window(game.mlx_ptr, game.n_col * SIZE, game.n_row * SIZE, "SO LONG");
	if (!game.window)
	{
		free(game.mlx_ptr);
		return NULL;
	}
}