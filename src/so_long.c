/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:24 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/04 21:33:36 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int main(int argc, char **argv)
{
	t_game_data	game;
	int i;
	
	i = 0;
	ft_memset(&game, 0, sizeof(t_game_data)); //MALLOC
	game.map = check_params(argc, argv, &game); //MALLOC
	//init(game);
	while (game.map[i])
		printf("%s\n", game.map[i++]);
	i = 0;
	while (game.map[i])
		free(game.map[i++]);
	free(game.map);
	return (0);
}
