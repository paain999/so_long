/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:17:41 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/10 21:59:33 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define SIZE 64

# define W  13
# define A 	0
# define S  1
# define D  2
# define ESC 53
# define UP  126
# define DOWN 125
# define LEFT  123
# define RIGHT  124
# define BUFFER_SIZE 20

typedef struct s_game_data
{
	void	*mlx_ptr;
	void	*window;
	void	*player;
	void	*exit;
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
	int		img_w;
	int		img_h;
	int		endgame;
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
void		check_params(int argc, char **argv, t_game_data *game, t_map_err err);
int			ft_print_map_errors(t_map_err map_err);
int			ft_countchar(int c, char *s);
void		check_path(t_game_data *game, t_map_err *err);
void		free_and_exit(t_game_data *game);
int			ft_draw_map(t_game_data *game);
void 		ft_draw_img(t_game_data *game, void *img,int y, int x);
void		init_imgs(t_game_data *game);
void		*ft_memset(void *src, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnstr(const char *s1, const char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_itoa(int n);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlen(const char *str);
void		free_map(char **map);
void		init(t_game_data *game);
void		display_moves(t_game_data *game);
void		ft_gamehooks(t_game_data *game);
void		print_winner(t_game_data *game);
void		player_w(t_game_data *game);
void		player_s(t_game_data *game);
void		player_d(t_game_data *game);
void		player_a(t_game_data *game);

char		*get_next_line(int fd);
char		*ft_strchr_gnl(char *str, int c);
char		*ft_strjoin_gnl(char *stash, char *buff);
int			ft_strlen_gnl(char *str);

#endif