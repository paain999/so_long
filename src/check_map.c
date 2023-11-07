/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:54 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/06 18:54:11 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**check_map(int fd, t_game_data *game, t_map_err map_err )
{
	char		*map_str;
	char		**map;
	int			i;

	i = 0;
	map_str = NULL;
	map = NULL;
	map_str = ft_readmap(fd, game, &map_err , map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (ft_print_map_errors(map_err))
	{
		while (map[i])
			free(map[i++]);
		free(map);
		exit(-1);
	}
	return map;
}

char	**check_params(int argc, char **argv, t_game_data *game, t_map_err map_err)
{
	int fd;

	if (argc != 2)
	{
		perror("ERROR!, Wrong number of arguments.");
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR!, Cannot read the file.");
		exit(-1);
	}
	if (!ft_strnstr(argv[1], ".ber"))
	{
		perror("ERROR!, Wrong file extension.");
		exit(-1);
	}
	return(check_map(fd, game, map_err));
}