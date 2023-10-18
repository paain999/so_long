#include "../include/so_long.h"

int	error_msg(char *msg)
{
	perror(msg);
	return 1;
}

int	ft_print_map_errors(t_map_err map_err)
{
	if (map_err.empty_line || map_err.inv_borders || map_err.inv_char || map_err.inv_n_collect
		|| map_err.inv_n_exit || map_err.inv_n_player || map_err.inv_rowlen)
	{
		if (map_err.empty_line)
			error_msg("ERROR!, Empty line.");
		if (map_err.inv_rowlen)
			error_msg("ERROR!, The map must be a rectangle.");
		if (map_err.inv_borders)
			error_msg("ERROR!, The map need to has borders.");
		if (map_err.inv_n_player)
			error_msg("ERROR!, Invalid number of players.");
		if (map_err.inv_n_exit)
			error_msg("ERROR!, Invalid exit number.");
		if (map_err.inv_n_collect)
			error_msg("ERROR!, Invalid collect number.");
		if (map_err.inv_char)
			error_msg("ERROR!, The map contains and invalid char.");
		return 1;
	}
	return 0;
}

static	int	ft_countchar(int c, char *s)
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

static void	ft_check_map_data(char *line, t_map_data *map_data, t_map_err *map_err, int islast, int isfirst)
{
	map_err->empty_line += (*line >= 9 && *line <= 13) ? 1 : 0;
	if(!map_data->n_col)
		map_data->n_col = (int)ft_strlen(line) - 1;
	map_err->inv_rowlen += ((map_data->n_col != (int)ft_strlen(line) - 1) && !islast);
	map_err->inv_rowlen -= ((map_data->n_col == ((int)ft_strlen(line) + islast) - 1) && islast);
	if(islast && (map_data->n_col == ((int)ft_strlen(line) + islast) - 1) && map_err->inv_rowlen)
		map_err->inv_rowlen--;
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


char *ft_readmap(int fd, t_map_data *map_data, t_map_err *map_err ,char *map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	map_err->inv_char = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!map_data->n_col)
				error_msg("ERROR!, Empty map");
			else
				ft_check_map_data(last_line, map_data, map_err, 1, 0);
			free(last_line);
			break ;
		}
		free(last_line);
		ft_check_map_data(line, map_data, map_err, 0, !map_data->n_row);
		last_line =ft_strdup(line);
		map_str = ft_strjoin(map_str, line);
		map_data->n_row++;
	}
	return(map_str);
}