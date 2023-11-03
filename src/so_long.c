/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:24 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/03 12:57:17 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int main(int argc, char **argv)
{
	t_map_data	map_data;
	t_game_data	game;
	int i;
	
	i = 0;
	ft_memset(&game, 0, sizeof(t_game_data)); //MALLOC
	game.map = check_params(argc, argv, &map_data); //MALLOC
	init(map_data, game);
	while (game.map[i])
		free(game.map[i++]);
	free(game.map);
	return (0);
}
