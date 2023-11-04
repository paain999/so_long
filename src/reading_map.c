/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:49:18 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/04 21:29:10 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*void	check_path(t_game_data game, t_map_err err)
{

}*/

static void	ft_check_map_data(char *line, t_game_data *map_data, t_map_err *map_err, int islast, int isfirst)
{
	map_err->empty_line += (*line >= 9 && *line <= 13) ? 1 : 0;
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


char *ft_readmap(int fd, t_game_data *map_data, t_map_err *map_err ,char *map_str)
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
		free(last_line);
		ft_check_map_data(line, map_data, map_err, 0, !map_data->n_row);
		last_line =ft_strdup(line);
		map_str = ft_strjoin(map_str, line);
		free(line);
		map_data->n_row++;
	}
	return(map_str);
}