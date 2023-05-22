/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:24 by dajimene          #+#    #+#             */
/*   Updated: 2023/05/22 16:27:27 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int main(int argc, char **argv)
{
	t_game so_long;
	
	if(argc != 2)
	{
		ft_putstr_fd("ERROR: Wrong number of arguments!", 1);
		return (0);
	}
	so_long.mlx_ptr = mlx_init();
	so_long = checkfile(so_long, argv[1]);
	return (0);
}
