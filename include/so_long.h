/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:17:41 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/10 00:11:40 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"

# define SIZE 32

# define W  13
# define A 	0
# define S  1
# define D  2
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
	int		n_row;
	int		n_col;
	int		n_collect;
	int		n_exit;
	int		n_player;
}			t_game_data;

typedef struct s_pointer
{
	int	x;
	int y;
}			t_pointer;


typedef struct s_map_err
{
	int	inv_rowlen;
	int inv_borders;
	int	inv_n_exit;
	int	inv_n_player;
	int	inv_n_collect;
	int inv_char;
	int empty_line;
	int inv_path;
}			t_map_err;


t_map_err	err_list(void);
char		**check_params(int argc, char **argv, t_game_data *game, t_map_err err);
int			ft_print_map_errors(t_map_err map_err);
int			ft_countchar(int c, char *s);
int			controls(int keycode, t_game_data *game);
void		check_path(t_game_data *game, t_map_err *err);
void		free_and_exit(t_game_data *game);
void		show_exit(t_game_data *game, char *str);
void		ft_put_graphics(t_game_data *game);
void 		ft_put_scene(t_game_data *game, int y, int x);
void		ft_put_images(t_game_data *game);
void		*ft_memset(void *src, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strnstr(const char *s1, const char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif