/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:00:01 by dajimene          #+#    #+#             */
/*   Updated: 2023/10/31 13:32:01 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "../../include/libft.h"

int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int ft_printstr(char *str);
int	ft_printnbr(int n);
int	ft_printpercent(void);
int	ft_print_unsigned(unsigned int n);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_hex(unsigned long long num, const char format);
#endif