/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:54 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/14 21:16:34 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_check_map_data(char *line, t_game_data *map_data, t_map_err *map_err, int islast, int isfirst)
{
	map_err->empty_line += (*line >= 9 && *line <= 13);
	if(!map_data->n_col)
		map_data->n_col = (int)ft_strlen(line) - 1;
	map_err->inv_rowlen += ((map_data->n_col != (int)ft_strlen(line) - 1) && !islast);
	map_err->inv_rowlen -= ((map_data->n_col == ((int)ft_strlen(line) + islast) - 1) && islast);
	if (!(line[0] == '1' && line[map_data->n_col - 1] == '1') 
		|| (ft_countchar('1', line) != map_data->n_col && isfirst) 
		|| (ft_countchar('1', line) != map_data->n_col && islast))
		map_err->inv_borders += 1;
	map_data->n_exit += ft_countchar('E', line);
	map_data->n_collect += ft_countchar('C', line);
	map_data->n_player += ft_countchar('P', line);
	map_err->inv_n_player = (map_data->n_player > 1 || map_data->n_player < 1 );
	map_err->inv_n_collect = (map_data->n_collect == 0);
	map_err->inv_n_exit = (map_data->n_exit > 1 || map_data->n_exit < 1);
	while (*line && line)
	{
		map_err->inv_char += (!ft_strchr("01CEP\n", *line));
		line++;
	}
}


static char *ft_readmap(int fd, t_game_data *map_data, t_map_err *map_err ,char *map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!map_data->n_col)
				perror("ERROR!, Empty map");
			else
				ft_check_map_data(last_line, map_data, map_err, 1, 0);
			free(last_line);
			free(line);
			break ;
		}
		if(last_line)
			free(last_line);
		ft_check_map_data(line, map_data, map_err, 0, !map_data->n_row);
		last_line =ft_strdup(line);
		map_str = ft_strjoin(map_str, line);
		free(line);
		map_data->n_row++;
	}
	return(map_str);
}

static void check_map(int fd, t_game_data *game, t_map_err map_err )
{
	char		*map_str;
	int			i;

	map_str = NULL;
	map_str = ft_readmap(fd, game, &map_err , map_str);
	game->map = ft_split(map_str, '\n');
	game->mapcpy = ft_split(map_str, '\n');
	free(map_str);
	if (ft_print_map_errors(map_err))
	{
		i = 0;
		while (game->mapcpy[i])
			free(game->mapcpy[i++]);
		free(game->mapcpy);
		i = 0;
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		exit(2);
	}
}

void	check_params(int argc, char **argv, t_game_data *game, t_map_err map_err)
{
	int fd;

	if (argc != 2)
	{
		perror("ERROR!, Wrong number of arguments.");
		exit(2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR!, Cannot read the file.");
		exit(2);
	}
	if (!ft_strnstr(argv[1], ".ber"))
	{
		perror("ERROR!, Wrong file extension.");
		exit(2);
	}
	check_map(fd, game, map_err);
}