/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:01:01 by dajimene          #+#    #+#             */
/*   Updated: 2023/10/31 13:34:50 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

static	int	formats(va_list args, char const format)
{
	int	len;
	
	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
			len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
			len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
			len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
			len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
			len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
			len += ft_printpercent();
	return(len);
}

int	ft_printf(const char *s, ...)
{
	int	len;
	int	i;
	va_list args;
	
	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += formats(args, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int main(void)
{
	int		n;
	char	h;
	
	h = 'h';
	n = 0;
	n = ft_printf("Letra: %c", h);
	printf("%d", n);
	return (0);
}