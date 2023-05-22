/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:17:41 by dajimene          #+#    #+#             */
/*   Updated: 2023/05/22 15:57:23 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
#include <mlx.h>
#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include "get_next_line.h"

typedef struct s_game
{
	int		fd;
	void	*mlx_ptr;
	void	*window;
	char	*map;
}	t_game;

t_game	checkfile(t_game game, char *map);
#endif