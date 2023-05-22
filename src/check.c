#include "../include/so_long.h"
static int checkwidth(char *map)
{
	int i;
	
	i = 0;
}
static void addmap(t_game game)
{
	int	i;
	char	*readed;

	i = 1;
	while (i)
	{
		if(!(readed = get_next_line(game.fd)))
			i = 0;
		else
			game.map = ft_strjoin(game.map, readed);
	}
	free(readed);
}

t_game	checkfile(t_game game, char *map)
{
	game.fd = open(map, O_RDONLY);
	if(game.fd < 0 && ft_strnstr(map, ".ber"))
	{
		ft_putstr_fd("Error reading file or wrong file extension!", 1);
		exit(-1);
	}
	addmap(game);
	close(game.fd);
	if(!game.map)
	{
		perror("This map is empty.");
		exit(-1);
	}
	if (checkwidth(game.map))
	{
		perror("Wrong map width.");
	}
	
}