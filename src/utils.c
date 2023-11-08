/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:48:44 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/08 19:02:41 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_print_map_errors(t_map_err map_err)
{
	if (map_err.empty_line || map_err.inv_borders || map_err.inv_char || map_err.inv_n_collect
		|| map_err.inv_n_exit || map_err.inv_n_player || map_err.inv_rowlen || map_err.inv_path)
	{
		if (map_err.empty_line)
			perror("Error\n Empty line.");
		if (map_err.inv_rowlen)
			perror("Error\n The map must be a rectangle.");
		if (map_err.inv_borders)
			perror("Error\n The map need to has borders.");
		if (map_err.inv_n_player)
			perror("Error\n Invalid number of players.");
		if (map_err.inv_n_exit)
			perror("Error\n Invalid exit number.");
		if (map_err.inv_n_collect)
			perror("Error\n Invalid collect number.");
		if (map_err.inv_char)
			perror("Error\n The map contains and invalid char.");
		if (map_err.inv_path)
			perror("Error\n There is not a valid path in this map.");
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
	map_err.inv_path = 0;
	return(map_err);
}
