#include "../include/so_long.h"

t_game	checkmap(t_game game, char *map)
{
	int fd;
	fd = open(map, O_RDONLY);

	if(fd < 0 && ft_strnstr(map, ".ber"))
	{
		ft_putstr_fd("Error reading file or wrong file extension!", 1);
		exit(0);
	}
	while ()
	{
		game.map = get_next_line
	}
	
}