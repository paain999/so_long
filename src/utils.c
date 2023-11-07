/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:48:44 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/07 09:55:58 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_p_pos(t_game_data *game)
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

char	**cpy_arr(char **dst, char **map, int size)
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

int	ft_print_map_errors(t_map_err map_err)
{
	if (map_err.empty_line || map_err.inv_borders || map_err.inv_char || map_err.inv_n_collect
		|| map_err.inv_n_exit || map_err.inv_n_player || map_err.inv_rowlen || map_err.inv_path)
	{
		if (map_err.empty_line)
			perror("ERROR!, Empty line.");
		if (map_err.inv_rowlen)
			perror("ERROR!, The map must be a rectangle.");
		if (map_err.inv_borders)
			perror("ERROR!, The map need to has borders.");
		if (map_err.inv_n_player)
			perror("ERROR!, Invalid number of players.");
		if (map_err.inv_n_exit)
			perror("ERROR!, Invalid exit number.");
		if (map_err.inv_n_collect)
			perror("ERROR!, Invalid collect number.");
		if (map_err.inv_char)
			perror("ERROR!, The map contains and invalid char.");
		if (map_err.inv_path)
			perror("ERROR!, There is not a valid path in this map.");
		return 1;
	}
	return 0;
}

int	ft_countchar(int c, char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return i;
}

void	free_and_exit(t_game_data game)
{
	int i;
	
	i = 0;
	while (game.map[i])
		free(game.map[i++]);
	free(game.map);
	/*free(game.mlx_ptr);
	free(game.player);
	free(game.exit_open);
	free(game.exit_closed);
	free(game.collectable);
	free(game.wall);
	free(game.floor);*/
	exit(1);
}