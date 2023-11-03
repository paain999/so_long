/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:54 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/03 13:02:10 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map_data ft_new_map(void)
{
	t_map_data	map_data;

	map_data.n_row = 0;
	map_data.n_col = 0;
	map_data.n_collect = 0;
	map_data.n_exit = 0;
	map_data.n_player = 0;
	return(map_data);
}

t_map_err	err_list(void)
{
	t_map_err	map_err;

	map_err.inv_borders = 0;
	map_err.inv_n_collect = 0;
	map_err.inv_n_exit = 0;
	map_err.inv_rowlen = 0;
	map_err.empty_line = 0;
	map_err.inv_n_player = 0;
	map_err.inv_char = 0;
	return(map_err);
}

char	**check_map(int fd, t_map_data *map_data)
{
	char		*map_str;
	char		**map;
	t_map_err	map_err;
	int			i;

	i = 0;
	map_str = NULL;
	map = NULL;
	*map_data = ft_new_map();
	map_err = err_list();
	map_str = ft_readmap(fd, map_data, &map_err , map_str);
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

char	**check_params(int argc, char **argv, t_map_data *map_data)
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
	return(check_map(fd, map_data));
}