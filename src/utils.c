/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:48:44 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/15 01:24:58 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_print_map_errors(t_game_data *map_err)
{
	if (map_err->empty_line || map_err->inv_borders
		|| map_err->inv_char || map_err->inv_n_collect
		|| map_err->inv_n_exit || map_err->inv_n_player
		|| map_err->inv_rowlen || map_err->inv_path)
	{
		if (map_err->empty_line)
			perror("\033[1;31mError\n Empty line.");
		if (map_err->inv_rowlen)
			perror("\033[1;31mError\n The map must be a rectangle.");
		if (map_err->inv_borders)
			perror("\033[1;31mError\n The map need to has borders.");
		if (map_err->inv_n_player)
			perror("\033[1;31mError\n Invalid number of players.");
		if (map_err->inv_n_exit)
			perror("\033[1;31mError\n Invalid exit number.");
		if (map_err->inv_n_collect)
			perror("\033[1;31mError\n Invalid collect number.");
		if (map_err->inv_char)
			perror("\033[1;31mError\n The map contains and invalid char.");
		if (map_err->inv_path)
			perror("\033[1;31mError\n There is not a valid path in this map.");
		return (1);
	}
	return (0);
}

int	ft_countchar(int c, char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			ft_putnbr_fd(n, fd);
		}
		else if (n / 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
