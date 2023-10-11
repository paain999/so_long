/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:24 by dajimene          #+#    #+#             */
/*   Updated: 2023/10/10 20:41:26 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int main(int argc, char **argv)
{
	char	**map;
	t_map_data	map_data;
	int i = 0;
	
	map = check_params(argc, argv, &map_data);
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	free(map);
	return (0);
}
