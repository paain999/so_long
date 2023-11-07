/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:49:18 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/07 10:33:18 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_p_pos(t_game_data *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				break;
			x++;
		}
		if (game->map[y][x] == 'P')
				break;
		y++;
	}
	game->player_x = x;
	game->player_y = y;
}

static char	**cpy_arr(char **dst, char **map, int size)
{
	int i;

	i = 0;
	dst = malloc(sizeof(char *) * size + 1);
	while (map[i])
	{
		dst[i] = ft_strdup(map[i]);
		i++;
	}
	dst[size] = 0;
	return dst;
}

static int is_valid_path(char **mapcpy,int y, int x)
{
	if (mapcpy[y][x] == 'E')
		return 1;
	if (mapcpy[y][x] != '1' && mapcpy[y][x] != 'F')
	{
		mapcpy[y][x] = 'F';
		if (is_valid_path(mapcpy ,y - 1, x) || is_valid_path(mapcpy ,y + 1, x) 
			|| is_valid_path(mapcpy ,y, x - 1) || is_valid_path(mapcpy ,y, x + 1))
		{
			return 1;
		}
		else
			mapcpy[y][x] = 'P';
	}
	return 0;
}
void	check_path(t_game_data game, t_map_err map_err)
{
	t_pointer	currentpos;
	int			i;
	
	i = 0;
	get_p_pos(&game);
	game.mapcpy = cpy_arr(game.mapcpy, game.map, game.n_row);
	currentpos.x = game.player_x;
	currentpos.y = game.player_y;
	if(!is_valid_path(game.mapcpy, currentpos.y, currentpos.x))
	{
		while (game.mapcpy[i])
			free(game.mapcpy[i++]);
		free(game.mapcpy);
		map_err.inv_path = 1;
		ft_print_map_errors(map_err);
		free_and_exit(game);
	}
	ft_putstr_fd("There is a valid path\n", 1);
	while (game.mapcpy[i])
		free(game.mapcpy[i++]);
	free(game.mapcpy);
}