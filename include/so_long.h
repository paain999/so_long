/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:17:41 by dajimene          #+#    #+#             */
/*   Updated: 2023/10/24 09:50:06 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
#include <mlx.h>
#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include "get_next_line.h"

typedef struct s_game_data
{
	void	*mlx_ptr;
	void	*window;
}			t_game_data;

typedef struct s_map_data
{
	int	n_row;
	int	n_col;
	int	n_collect;
	int	n_exit;
	int	n_player;
}			t_map_data;

typedef struct s_map_err
{
	int	inv_rowlen;
	int inv_borders;
	int	inv_n_exit;
	int	inv_n_player;
	int	inv_n_collect;
	int inv_char;
	int empty_line;
}			t_map_err;


char		**check_params(int argc, char **argv, t_map_data *map_data);
char		**check_map(int fd, t_map_data *map_data);
int			error_msg(char *msg);
char		*ft_readmap(int fd, t_map_data *map_data, t_map_err *map_err ,char *map_str);
int			ft_print_map_errors(t_map_err map_err);
t_map_err	err_list(void);
t_map_data	ft_new_map(void);

#endif