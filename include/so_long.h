/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:17:41 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/03 13:28:54 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "libft.h"
# include <fcntl.h>
# include "get_next_line.h"

# define SIZE 32

# define W  13
# define A 	0
# define S  1
# define D  2
# define Q  12
# define ESC 53
# define UP  126
# define DOWN 125
# define LEFT  123
# define RIGHT  124

typedef struct s_game_data
{
	void	*mlx_ptr;
	void	*window;
	void	*player;
	void	*exit_open;
	void	*exit_closed;
	void	*collectable;
	void	*wall;
	void	*floor;

	char	**map;
	char	**mapcpy;
	
	int		w_width;
	int 	w_height;
	int		steps;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
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
void		init(t_map_data map_data, t_game_data game);
int			ft_countchar(int c, char *s);

#endif