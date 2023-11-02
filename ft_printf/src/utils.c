/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:18:51 by dajimene          #+#    #+#             */
/*   Updated: 2023/10/31 13:34:36 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (str == NULL)
	{
		write(1,"(null)", 6);
		return (6);
	}
	while (str[i])
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;
	
	len = 0;
	num = ft_itoa(n);
	len += ft_printstr(num);
	free(num);
	return (len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}