/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:16:45 by dajimene          #+#    #+#             */
/*   Updated: 2023/10/31 13:34:20 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int	ft_ptrlen(uintptr_t ptr)
{
	int	len;
	
	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}
static	void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}
int	ft_print_ptr(unsigned long long ptr)
{
	int	len;
	
	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1,"0", 1);
	else
	{
		len += ft_ptrlen(ptr);
		ft_putptr(ptr);
	}
	return (len);
}