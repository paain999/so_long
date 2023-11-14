/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:49:18 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/14 10:12:51 by dajimene         ###   ########.fr       */
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

static int is_valid_path(char **mapcpy,int y, int x)
{
	if (mapcpy[y][x] == 'E')
		return 1;
	if (mapcpy[y][x] != '1' && mapcpy[y][x] != 'F' && mapcpy[y][x] != '\0')
	{
		mapcpy[y][x] = 'F';
		if (is_valid_path(mapcpy ,y - 1, x) || is_valid_path(mapcpy ,y + 1, x) 
			|| is_valid_path(mapcpy ,y, x - 1) || is_valid_path(mapcpy ,y, x + 1))
			return 1;
	}
	return 0;
}
void	check_path(t_game_data *game, t_map_err *map_err)
{
	t_pointer	currentpos;
	int			i;

	get_p_pos(game);
	currentpos.x = game->player_x;
	currentpos.y = game->player_y;
	i = 0;
	if(!is_valid_path(game->mapcpy, currentpos.y, currentpos.x))
	{
		while (game->mapcpy[i])
			free(game->mapcpy[i++]);
		free(game->mapcpy);
		map_err->inv_path = 1;
		ft_print_map_errors(*map_err);
		free_and_exit(game, 2);
	}
	ft_putstr_fd("There is a valid path\n", 1);
	while (game->mapcpy[i])
			free(game->mapcpy[i++]);
		free(game->mapcpy);
}